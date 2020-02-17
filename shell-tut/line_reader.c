#include <stdio.h>
#include <stdlib.h>

#define LSH_RL_BUFSIZE 1024

char *lsh_read_line(void) {

    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) *bufsize);
    int c;

    if(!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(1);
    }

    while(1) {

        c = getchar();

        // If we hit EOF, replace it with a null character and return
        if(c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // If we have exceeded the buffer, reallocate
        if(position >=1024) {
            bufsize += LSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if(!buffer) {
                fprintf(stderr, "lsh: reallocation error\n");
                exit(1);
            }
        }
    }
}
