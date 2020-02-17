#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line_reader.h"
#include "parser.h"

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

int lsh_execute(char **args);

void lsh_loop(void) {

    char *line;
    char **args;
    int status = 0;

    do {
        printf("> ");
        line = lsh_read_line();
        args = lsh_split_line(line);
        //status = lsh_execute(args);

        free(line);
        free(args);
    } while(status);
}

int main(void) {
    // load config files if any
    //
    // run command loop
    lsh_loop();

    // Perform any shutdown/cleanup.
    return 0;
}
