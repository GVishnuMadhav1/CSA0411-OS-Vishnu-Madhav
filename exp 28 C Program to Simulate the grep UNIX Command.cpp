#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], pattern[100], line[500];
    int line_number = 0, found = 0;

    // Input: file name and pattern to search
    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("\nLines containing '%s':\n\n", pattern);

    // Read the file line by line
    while (fgets(line, sizeof(line), fp) != NULL) {
        line_number++;

        // Check if the pattern exists in the current line
        if (strstr(line, pattern) != NULL) {
            printf("Line %d: %s", line_number, line);
            found = 1;
        }
    }

    if (!found)
        printf("\nPattern '%s' not found in the file.\n", pattern);

    fclose(fp);
    return 0;
}

