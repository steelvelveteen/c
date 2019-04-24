#include<stdio.h>

int main(int argc, char **argv) {

    int i;
    char *days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

    for (i = 0; i < 10; i++) {
        printf("Day[%d] -> %s\n", i, days[i]);
    }

    return 0;
}