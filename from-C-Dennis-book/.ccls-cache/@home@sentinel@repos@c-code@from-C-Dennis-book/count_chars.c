#include <stdio.h>

int main()
{
int x;
char pos;
unsigned int long charcount, wordcount, linecount;

charcount = 0;
wordcount = 0;
linecount = 0;

while((pos=getc(stdin)) != EOF)
{
    if (pos != '\n' && pos != ' ')
    {
    charcount+=1;
    }

    if (pos == ' ' || pos == '\n')
    {
    wordcount +=1;  
    }

    if (pos == '\n')
    {
    linecount +=1;
    }

}

    if (charcount>0)
    {
    wordcount+=1;
    linecount+=1;
    }

printf( "%lu %lu %lu\n", charcount, wordcount, linecount );
return 0;
}
