#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(-1);
}

int main (int argc, char **argv) {
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);

    if (listener_d == -1) {
        error("Can't open socket.");
    }

    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    int c = bind (listener_d, (struct sockaddr *) &name, sizeof(name));
    if (c == -1) {
        error("Can't bind to socket.");
    }

    if (listen(listener_d, 10) == -1) {
        error("Can't listen.");
    }
}