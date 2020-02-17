#include<stdio.h>
#include<unistd.h> // unix syscalls
#include<sys/types.h>

int main(int argc, char **argv)
{
    printf("You are now inside the child. My pid: %d\n", getpid());
    return 0;
}
