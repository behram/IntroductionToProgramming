#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum
{
    EQUALS, ADD, SUBTRACT, NUMBER, WORD, PREV, MULTIPLY, DIVIDE
} TokenType;

TokenType getNextToken(char tk[], int len);
char * lineCalc();
float operations(float a, float b, TokenType operation);

#endif // FUNC_H_INCLUDED
