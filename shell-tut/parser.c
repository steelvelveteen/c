#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

char **lsh_split_line(char *line) {
    int position = 0;
    int bufsize = LSH_TOK_BUFSIZE; // 64
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if(tokens == NULL) {
        fprintf(stderr, "lsh: allocation error.\n");
        exit(1);
    }

    token = strtok(line, LSH_TOK_DELIM);
    while(token != NULL) {
        tokens[position] = token;
        position++;

        if(position >= bufsize) {
            bufsize += LSH_TOK_BUFSIZE;
            tokens = realloc(bufsize, sizeof(char *));
            
            if(tokens == NULL) {
                fprintf(stderr, "lsh: reallocation error.\n");
                exit(1);
            }
        }
        token = strtok(NULL, LSH_TOK_DELIM);
    }

    tokens[position] = token;
    int t = 0;
    for (t = 0; t < sizeof(tokens); t++) {
        fprintf(stdout, "Token: %s\n", tokens[t]);
    }
    
    return tokens;
}
