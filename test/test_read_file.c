#include <stdio.h>

int main(int argc, char** argv)
{
    char *crash = NULL;
    FILE *fp;
    char c;

    if (argc < 2) {
        // printf("Usage: %s <input file>\n", argv[0]);
        return 0;
    }

    fp = fopen(argv[1], "rb");
    if (!fp) {
        // printf("Error opening file\n");
        return 0;
    }

    if (fread(&c, 1, 1, fp) != 1) {
        // printf("Error reading file\n");
        fclose(fp);
        return 0;
    }
    if (c != 't') {
        // printf("Error 1\n");
        fclose(fp);
        return 0;
    }

    if (fread(&c, 1, 1, fp) != 1) {
        // printf("Error reading file\n");
        fclose(fp);
        return 0;
    }
    if (c != 'e') {
        // printf("Error 2\n");
        fclose(fp);
        return 0;
    }

    if (fread(&c, 1, 1, fp) != 1) {
        // printf("Error reading file\n");
        fclose(fp);
        return 0;
    }
    if (c != 's') {
        // printf("Error 3\n");
        fclose(fp);
        return 0;
    }

    if (fread(&c, 1, 1, fp) != 1) {
        // printf("Error reading file\n");
        fclose(fp);
        return 0;
    }
    if (c != 't') {
        // printf("Error 4\n");
        fclose(fp);
        return 0;
    }

    // got 'test' from input file
    // printf("!!!!!!!!!!OK, CRASH NOW!!!!!!!!!!\n");

    //cause a crash
    crash[0] = 1;

    fclose(fp);

    return 0;
}

