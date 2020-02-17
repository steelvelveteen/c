#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

int main(int argc, char **argv) {

    char name[] = "Jose Ramon Vico Lopez";
    char *line = malloc(sizeof(char*) * TOK_BUFSIZE);
    strcpy(line, "Antonio Ramon Diaz de Vivar");

    fprintf(stdout, "%s\n",name);
    fprintf(stdout, "%d\n", strlen(name));

    // Let's tokenize name[]
    // char **tokens = malloc(sizeof(char *) * TOK_BUFSIZE);
    // char *token;
    // int index = 0;

    // token = strtok(name, TOK_DELIM);

    // while(token != NULL) {

    //     tokens[index] = token;
    //     index++;
    //     token = strtok(NULL, TOK_DELIM);

    // }

    // for(index = 0; index < sizeof(tokens); index++) {

    //     if(tokens[index] != NULL)
    //         fprintf(stdout, "Tokens list: %s\n", tokens[index]);
    // }

    // Let's tokenize *line now
    char **tokens2 = malloc(sizeof(char*) * TOK_BUFSIZE);
    char *token2;
    int index = 0;

    token2 = strtok(line, TOK_DELIM);
    while(token2 != NULL) {
        tokens2[index] = token2;
        index++;
        token2 = strtok(NULL, TOK_DELIM);
    }

    for(index = 0; index < sizeof(tokens2); index++) {
        if(tokens2[index] != NULL)
            fprintf(stdout, "Tokens2 list: %s\n", tokens2[index]);
    }
    return 0;
}
