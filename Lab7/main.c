#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "func.h"

int main(int argc, char * argv[])
{
    char * result;
    while(result != NULL)
    {
        result = lineCalc();
        if(result != NULL)
            printf(" has the value: %s \n", result);
    }
    printf("\n");

    return 0;
}
