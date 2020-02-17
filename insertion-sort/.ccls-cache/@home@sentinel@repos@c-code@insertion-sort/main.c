/* insertion sort algorithm implementation
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int array[] = {1, 5, 4, 9, 7, 2 };
    int length = sizeof array / sizeof(int);
    //printf("arrayay length: %d\n", length);
    int i, key, j;
    for(i = 1; i < length; i++) {
        key = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

    for(int i = 0; i < length ; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

