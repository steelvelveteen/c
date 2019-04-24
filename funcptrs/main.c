#include<stdio.h>

* Here I play with function pointers from my dear memory */

int add (int a, int b);
int sub (int a, int b);

int main(int argc, char **argv)
{
    printf("Choose operation: addition or subtraction\n");
    char op;
    scanf("%c",&op);

    int (*func_ptr) (int a, int b);
    int number1 = 10;
    int number2 = 7;

    if (op == 'a')
    {
        printf("Addition operation ...");
        int result;
        func_ptr = add;
        result = func_ptr(number1, number2);
        printf("Result: %d\n",result);

    } else {
        printf("Subtraction operaton ...");
        func_ptr = sub;
        int result = func_ptr(number1, number2);
        printf("Result: %d\n",result);
    }
}

int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
