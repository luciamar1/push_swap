#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    while(*argv)
    {
        while(**argv)
        {
            printf("jujiju  %c\n", **argv);
            (*argv) ++;
        }
        argv++;
    }
    
    return (0);
}