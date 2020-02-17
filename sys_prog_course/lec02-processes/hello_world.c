#include<stdio.h>
#include<unistd.h> // unix syscalls
#include<sys/types.h>

int main(int argc, char *argv)
{
    printf("Child program PID: %d\n", getpid());
    printf("Hello world program running ...\n");
    return 0;
}

