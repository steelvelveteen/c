#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

void handle_error(char *msg) {
    fprintf(stderr, "Error...%s\n", msg,strerr(errno));
    exit(-1);
}

int main (int argc, char **argv) {

    pthread_t t0;
    pthread_t t1;

    return 0;
}
