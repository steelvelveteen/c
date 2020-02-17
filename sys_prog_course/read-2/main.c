/* author: Joey Vico
 * email: joeyvico@gmail.com
 * license: MIT
 * build: gcc main.c -o main
 * run: ./main
 * misc: open a file that already containts some text,
 * read the text into a buffer and print it out char by char,
 * no strings cheating here.
 */

#include<stdio.h>
#include<stdlib.h> // exit(1)
#include<unistd.h> // unix syscalls
#include<fcntl.h>
#include<sys/types.h>
#include<string.h> // strlen strcmp strcat ...

int main(int argc, char *argv)
{
    // Create file descriptor to open random.txt file
    int fd;
    fd = open("random.txt", O_RDWR, 0755);
    if (fd < 0)
    {
        printf("There was an error opening the file.\n");
        exit(1);
    }

    // Read contents of file into buffer
    char buffer[200]; // reserving 200 bytes_count
    int bytes_count = read(fd, buffer, sizeof(buffer) - 1);
    printf("%d bytes read from file.\n", bytes_count);

    // Print out the contents of the buffered text.
    write(1, buffer,150);
    fprintf(stdout,"\n");

    //Close the file
    fd = close(fd);
    if (fd < 0)
    {
        printf("There was an error closing the file.\n");
        exit(1);
    }

    return 0;
}


