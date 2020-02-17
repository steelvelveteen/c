#include <stdio.h>

int main(void) {

    long nc = 0;
    
    while((getchar() != EOF)) {
        ++nc;

         fprintf(stdout, "%ld\n", nc);
    
    }

    return 0;
}
