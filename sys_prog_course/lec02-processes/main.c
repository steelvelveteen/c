#include<stdio.h>
#include<unistd.h> // unix syscalls
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv)
{
    printf("Fork program\n");
    printf("Current pid: %d\n", getpid());
    pid_t pid = fork();

    if (pid == 0)
    {
        //printf("I'm in the child now because my PID is %d zero.\n", pid);
        printf("PID: %d\n", pid);
        char *args[] = { "hello_world", NULL };
        execv("hello_world", args);
    } else {
        wait(NULL); // this is to wait for the child process to complete
        printf("... and I'm the continuation of the parent with pid: %d\n", getpid());
    }

    return 0;
}

