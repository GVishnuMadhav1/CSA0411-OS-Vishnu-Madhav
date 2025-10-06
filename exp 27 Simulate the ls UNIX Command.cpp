#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main() {
    struct dirent *de;          // Pointer for directory entry
    DIR *dr = opendir(".");     // Open current directory

    if (dr == NULL) {
        perror("Could not open current directory");
        exit(EXIT_FAILURE);
    }

    printf("Files and directories in current folder:\n\n");

    // Read and print all entries in directory
    while ((de = readdir(dr)) != NULL) {
        // Skip hidden files (names starting with '.')
        if (de->d_name[0] != '.')
            printf("%s\n", de->d_name);
    }

    closedir(dr);
    return 0;
}

