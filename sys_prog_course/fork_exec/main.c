#include<stdio.h>
#include<stdlib.h> // exit(1)
#include<unistd.h> // unix syscalls
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char **argv)
{
    printf("Current pid: %d\n", getpid());
    pid_t pid = fork();
    if(!pid)
    {
        printf("Inside child process. Pid: %d\n", getpid());
        char *args[] = { "other", NULL };
        execv("other", args);
    } else {
        wait(NULL);
        printf("Continuation of parent process.\n");
        printf("Good bye!\n");
    }
    return 0;
}

