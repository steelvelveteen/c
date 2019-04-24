#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{

    int c;
    while ((c = getopt(argc, argv, "abch")) != -1)
    {
        switch (c)
        {
        case 'h':
            printf("Help.\n");
            break;
        case 'a':
            printf("a option.\n");
            break;
        case 'b':
            printf("b option.\n");
            break;
        case '?':
            printf("Unknown option.\n");
            break;
        default:
            printf("Usage abc or h for help.\n");
            break;
        }
    }

    return 0;
}