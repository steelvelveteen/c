#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TOK_BUFSIZE 64
#define DELIM " \t\r\n\a"

int main(int argc, char **argv) {

    int position = 0;
    // ! Warning. You can't use char *line = "string", that is a string literal
    char line[] = "one two three\n";
    char **tokens = malloc(TOK_BUFSIZE * sizeof(char*));
 //fprintf(stdout, "Size of tokens: %d\n", sizeof(tokens));
    char *token;

    if(!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(1);
    }

    token = strtok(line, DELIM);
    while(token != NULL) {
        tokens[position] = token;
        position++;

        token = strtok(NULL, DELIM);

    }
    tokens[position] = token;

    // Testing tokens
    int t = 0;
    for (t = 0; t < sizeof(tokens); t++) {

        fprintf(stdout, "Token: %s\n",tokens[t]);
    }
    return 0;
}
