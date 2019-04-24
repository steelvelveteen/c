#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<pthread.h>

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(-1);
}

void *my_turn(void *a) {
    char *msg = (char *) a;
    int i = 0;
    for (i = 0; i < 5; i++) {
        printf("It's my turn. %s\n ", msg);
        sleep(1);
    }
    return NULL;
}

void *your_turn(void *b) {
    char *msg = (char *) b;
    int i = 0;
    for (i = 0; i < 5; i++) {
        printf("Its your turn. %s\n", msg);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char **argv) {

    pthread_t t0;
    pthread_t t1;
    char *msg1 = "First thread...";
    char *msg2 = "Second thread...";

    if (pthread_create(&t0, NULL, my_turn, msg1) == -1) {
        error("Can't create thread t0.");
    }
    if (pthread_create(&t1, NULL, your_turn, "Arg 02") == -1) {
        error("Can't create thread t1.");
    }

    void *result;
    if(pthread_join(t0, &result) == -1) {
        error("Couldn't join thread.");
    } else {
        printf("Joined thread successfull. %s\n", result);
    }

    pthread_join(t1, &result);
    return 0;
}
