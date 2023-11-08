#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *path = getenv("PATH");
    if (!path) {
        perror("environment");
        return EXIT_FAILURE;
    }

    char *token = strtok(path, ":");
    int found = 0;

    while (token != NULL) {
        DIR *dir = opendir(token);

        if (dir) {
            struct dirent *entry;
            while ((entry = readdir(dir)) != NULL) {
                if (strcmp(entry->d_name, argv[1]) == 0) {
                    printf("Found: %s/%s\n", token, argv[1]);
                    found = 1;
                    break;
                }
            }
            closedir(dir);
        }

        token = strtok(NULL, ":");
    }

    if (!found) {
        printf("%s not found in the PATH.\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

