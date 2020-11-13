#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

int main(int argc, char **argv) {
	// printf("Child: %s\n", getenv("ENV_FROM_PARENTS"));
	int shmid = atoi(getenv("ENV_FROM_PARENTS"));
	printf("%d\n", shmid);
	char *buf = shmat(shmid, NULL, 0);
	strcpy(buf, "GIFT FROM SON");
	// shmctl(shmid, IPC_RMID, NULL);
	return 0;
}