#include <stdio.h>
#include <stdlib.h>

FILE * Open_file (char *name)
{
     FILE * fp;
     fp = fopen(name, "r+");
     return fp;
}

int main(int argc, char* argv[])
{
    FILE * fp = Open_file(argv[1]);
    char letter = fgetc(fp);
    int amount_of_nucl = 0;
    int amount_of_N = 0;
    int number_of_consecutive_N = 0;
    int amount_of_repeat = 0;
    while (letter != EOF)
    {
        amount_of_nucl = amount_of_nucl + 1;
        if (letter == 'N')
        {
            amount_of_N = amount_of_N + 1;
            number_of_consecutive_N = number_of_consecutive_N +1;
        }
        if (letter != 'N')
        {   
            if (number_of_consecutive_N > 50)
                amount_of_repeat = amount_of_repeat + 1;
            number_of_consecutive_N = 0;
        }
        letter = fgetc(fp);
    }
    printf("Amount of N %d \n", amount_of_N);
    printf("Percentage of nucleotides N %d \n", div(amount_of_nucl, amount_of_N));
    printf("Amount of repeat sequences N %d \n", amount_of_repeat);
}