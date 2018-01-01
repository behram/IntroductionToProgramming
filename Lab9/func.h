#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char name[20];
    char * remarks;
    int age;
    float weight;
} personalData;

int readPtrData(personalData ar[], int len);
personalData getPersonPtr(char * line);
int semicolonCounter(char *line);

void weightSort(personalData data[], int len);
int cmpWeight(const void *a, const void *b);

void remarkstSort(personalData data[], int len);
int cmpRemarks(const void *a, const void *b);

void printAllData(personalData data[],int len);
void printData (personalData data[], int len);
void printPtrData (personalData data[], int len);


#endif
