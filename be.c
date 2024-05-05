#include <stdlib.h>
#include <stdio.h>

void check_error(int num)
{
    if (num == 1)
        printf("Not a number");
    if (num == 2)
        printf("SPACE");
    exit(1);
}

void    check_space(char **args)
{
    int i;
    int j;
    int spcs;

    i = 1;
    j = 0;
    while (args[i])
    {
        j = 0;
        while (args[i][j])
        {
            if (args[i][j] == ' ')
                spcs++;
            j++;
        }
        if (j == spcs)
            check_error(2);
        i++;
    }
}

int main(int argc, char **argv)
{
    check_space(argv);
    
}