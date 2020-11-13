#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <spawn.h>
#include <sys/shm.h>

extern char **environ;

int main(int argc, char **argv) {

	int shmid = shmget(IPC_PRIVATE, 1000, IPC_CREAT | IPC_EXCL | 0600);
	if (shmid < 0) perror("shmget()");
	char shm_str[100];
	sprintf(shm_str, "%d", shmid);
	puts(shm_str);
	setenv("ENV_FROM_PARENTS", shm_str, 1);

	pid_t child_pid = fork();
	if (!child_pid) {
	
		// execv("./child", NULL);

		int status;

		pid_t tmp;
		status = posix_spawn(&tmp, "./child", NULL, NULL, NULL, environ);
		if (status != 0) perror("posix_spawn");
		waitpid(tmp, &status, 0);
		exit(0);
	} else {
		int status;
		waitpid(child_pid, &status, 0);
		char *buf = shmat(shmid, NULL, 0);
		if (buf == (void *)-1) perror("shmat()");
		puts(buf);
	}
	return 0;
}