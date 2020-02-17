#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *do_stuff(void *arg)
{
    printf("This is thread %ld\n", (long) arg);
    return (void*) arg + 1;
}

int main(void)
{
    int num_threads = 5;
    pthread_t threads[num_threads];

    long i = 0;
    for (i = 0; i < num_threads; i++)
    {
        pthread_create(&threads[i], NULL, do_stuff, (void*)i);
    }

    void *result;
    for (i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], &result);
        printf("Returned from thread %ld the result %ld\n", (long)i, (long) result);
    }
}
