#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
    // Remove a file using syscalls
    // int remove(const char *pathname);
    // returns -1 if error, 0 if ok
    //
    int file;
    file = open("newfile.txt", O_RDWR | O_CREAT, 0755);
    if(file < 0)
    {
        printf("Error creating/opening file\n");
        exit(1);
    } else {
        printf("Success creating/opening file.\n");
    }

    int clo;
    clo = close(file);
    if (clo < 0)
    {
        printf("Error closing file\n");
        exit(1);
    } else {
        printf("Success closing file.\n");
    }

    int rem;
    rem = remove("newfile.txt");
    if (rem < 0)
    {
        printf("Error removing file.\n");
        exit(1);
    } else {
        printf("Success removing file\n");
    }
    
    return 0;
}
