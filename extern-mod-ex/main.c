#include <stdio.h>
#include <stdlib.h>

int a = 5;
extern int value;
int main(void)
{
    printf("external to this scope a: %d\n", a);
    printf("external variable a: %d\n", value);
    return 0;
}
