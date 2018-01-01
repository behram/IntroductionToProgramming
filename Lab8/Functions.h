#ifndef LABS_H_INCLUDED
#define LABS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    char * remarks;
    int age;
    float weight;
} personalData;

personalData getPersonDesc(char * line);
int readData(personalData ar[], int len);
int getOldestPerson(personalData data[]);
int getSlimmestPerson(personalData data[], int len);
void printInfo(personalData ar[], int idx, char *msgOk, char *msgbad);

#endif // LABS_H_INCLUDED
