/* author: Joey Vico
 * email: joeyvico@gmail.com
 * license: MIT
 * build: gcc main.c -o main
 * run: ./main
 * misc: Function pointers
 */

#include<stdio.h>

int add(int a, int b);
int subtract(int a, int b);

int main(int argc, char *argv)
{
   int a;
   int b;
   int result;
   int (*fun_ptr)(int a, int b);

   a = 25;
   b = 10;
   fun_ptr = add;
   result = fun_ptr(a, b);
   printf("Adding a and b: %d\n", result);

   fun_ptr = subtract;
   result = fun_ptr(a, b);
   printf("Subtract a and b: %d\n", result);
   return 0;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

