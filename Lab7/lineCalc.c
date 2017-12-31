#include <stdio.h>
#include <stdlib.h>
#include "func.h"

static float prevResult;

char * lineCalc()
{
    const int N = 256;
    TokenType operation;    //used for setting an appropriate operator
    bool is_equals = false; //to check if EQUALS variable was loaded
    bool is_value = false;  //to check if the value was calculated

    static char result2Return[20];
    float value;
    float number[2] = {0};  //an array to load numbers
    char str[N];

    while(scanf("%s", str) != EOF)
    {
        printf("%s ", str);
        if(is_value)    //if there was a value, reset the number array and set is_value to false
        {
            number[1] = 0;
            is_value = false;
        }
        switch(getNextToken(str, N))
        {
        case ADD:
            operation = ADD;
            break;
        case SUBTRACT:
            operation = SUBTRACT;
            break;
        case MULTIPLY:
            operation = MULTIPLY;
            break;
        case DIVIDE:
            operation = DIVIDE;
            break;
        case PREV:
            number[0] = prevResult;
            break;
        case WORD:
            break;
        case NUMBER:
            if(number[0] == 0)
                number[0] = atof(str);
            else
                number[1] = atof(str);
            break;
        case EQUALS:
            is_equals = true;
            break;
        default:
            break;
        }
        if(number[0] != 0 && number[1] != 0)
        {
            value = operations(number[0], number[1], operation);    //set value using appropriate operation
            prevResult = value;     //set prevResult to this value
            number[0] = value;
            is_value = true;        //there's a value
        }
        if(is_equals)    //if there was an equals_sign, return the value
        {
            is_equals = false;
            sprintf(result2Return, "%4.2f", value); //to convert a number to a string with the specified precision
            number[0] = 0;      //reset that array
            number[1] = 0;
            return result2Return;
        }
    }
    return NULL;    //EOF
}
