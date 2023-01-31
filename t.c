#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(char **argv)
{
    printf("hoal %s\n", *(argv));
    while(*(*(argv)) != '\0')
    {
        printf("%c\n", **argv);
        *argv = *argv + 1;
    }
}