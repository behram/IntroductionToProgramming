#include <stdio.h>
#include <stdlib.h>
#include "func.h"

TokenType getNextToken(char tk[], int len)
{
    char pluss[] = "+";
    char add[] = "add";
    char equals[] = "equals";
    char equal_sign[] = "=";
    char subtract[] = "subtract";
    char minuss[] = "-";
    char prev[] = "prev";
    char prev_result[] = "prev_result";
    char multiply[] = "multiply";
    char times[] = "*";
    char divide[] = "divide";
    char division_sign[] = "/";

    if(strstr(tk, add) != NULL || strstr(tk, pluss) != NULL)    //checks if strings are the same
    {
        return ADD;
    }
    else if(strstr(tk, equals) != NULL || strstr(tk, equal_sign) != NULL)
    {
        return EQUALS;
    }
    else if(strstr(tk, subtract) != NULL || strstr(tk, minuss) != NULL)
    {
        return SUBTRACT;
    }
    else if(strstr(tk, prev) != NULL || strstr(tk, prev_result) != NULL)
    {
        return PREV;
    }
    else if(strstr(tk, multiply) != NULL || strstr(tk, times) != NULL)
    {
        return MULTIPLY;
    }
    else if(strstr(tk, divide) != NULL || strstr(tk, division_sign) != NULL)
    {
        return DIVIDE;
    }
    else if(isdigit(tk[0])) //checks if the first char is a number
    {
        return NUMBER;
    }
    return WORD;    //otherwise return word
}
