// int read(fd, buf, nbytes)
// description read nbytes from fd into buffer
// returns number of bytes successfully read
// -1 if error, 0 otherwise

/* author: Joey Vico
 * email: joeyvico@gmail.com
 * license: MIT
 * date: 18 Sep 2020
 */

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main()
{
    /* Open file using unix syscall open */
    int file_open = open("random.txt",O_RDWR | O_CREAT, 755);
    if (file_open < 0)
    {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[200];
    int bytes_read = read(file_open, buffer, 150);
    if(bytes_read < 0)
    {
        printf("Error reading file\n");
        exit(1);
    } else {
        printf("%d bytes read into buffer\n", bytes_read);
        printf("%.*s\n",bytes_read, buffer);
    }

    return 0;
}
