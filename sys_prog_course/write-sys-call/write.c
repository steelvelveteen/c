/* author: Joey Vico
 * email: joeyvico@gmail.com
 * license: MIT
 * build: gcc main.c -o main
 * run: ./main
 * misc: using write syscall.
 * int write(fd, buf, nbytes)
 * returns number of bytes written
 * -1 if error, 0 otherwise
 */

#include<stdio.h>
#include<stdlib.h> // exit(1)
#include<unistd.h> // unix syscalls
#include<fcntl.h>
#include<sys/types.h>
#include<string.h> // strlen strcmp strcat ...

int main(int argc, char *argv)
{
    int fd = open("random.txt", O_RDWR | O_CREAT, 0777);
    if (fd < 0) {
        fprintf(stdout, "There was an error opening file.\n");
        exit(1);
    }

    char *write_this = "I am a text to go into the file.";
    int write_size;
    write_size = write(fd, write_this, strlen(write_this)); 

    // Let's test it


    return 0;
}




