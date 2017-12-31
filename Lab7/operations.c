#include <stdio.h>
#include <stdlib.h>
#include "func.h"

float operations(float a, float b, TokenType operation)
{
    switch(operation)
    {
    case ADD:
       return a+b;
    case SUBTRACT:
        return a-b;
    case MULTIPLY:
        return a*b;
    case DIVIDE:
        return a/b;
    default:
        break;
    }
}
