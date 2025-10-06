#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
    int fd;
    char buffer[200];
    ssize_t bytes;

    // Create or open a file
    fd = open("file_demo.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    printf("File created/opened successfully: file_demo.txt\n");

    // Write data into the file
    const char *data = "Hello! This is a demo file for file management operations.\n"
                       "We are performing file write, read, append, and delete.\n";

    bytes = write(fd, data, strlen(data));
    if (bytes < 0) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("Data written successfully to file.\n");

    // Move file pointer to the beginning
    lseek(fd, 0, SEEK_SET);

    // Read data from the file
    bytes = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes < 0) {
        perror("Error reading file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    buffer[bytes] = '\0';

    printf("\nContent read from file:\n");
    printf("%s\n", buffer);

    close(fd);

    // Append data to the file
    fd = open("file_demo.txt", O_WRONLY | O_APPEND);
    if (fd < 0) {
        perror("Error reopening file for append");
        exit(EXIT_FAILURE);
    }

    const char *extra = "This new line is appended at the end of the file.\n";
    bytes = write(fd, extra, strlen(extra));
    if (bytes < 0) {
        perror("Error appending to file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("Data appended successfully.\n");

    close(fd);

    printf("\nFile management operations completed successfully.\n");
    return 0;
}

