#include "Functions.h"

personalData getPersonDesc(char * line)
{
    personalData person;
    char * token;

    token = strtok(line, ";");
    snprintf(person.name, 20, "%s", token);

    token = strtok(NULL, ";");
    if(atoi(token) != 0)
        person.age = atoi(token);
    else
        puts("Not a valid age.");

    token = strtok(NULL, ";");
    if(atof(token) != 0)
        person.weight = atof(token);
    else
        puts("Not a valid weight.");

    token = strtok(NULL, ";");
    person.remarks = malloc(50);
    snprintf(person.remarks, 50, "%s", token);

    return person;
}

int readData(personalData ar[], int len)
{

    char line[100];
    char *wsk;

    int i = 0;

    while(fgets(line, sizeof(line), stdin) != NULL)
    {
        if(i < len-1)
        {
            wsk = line;
            ar[i] = getPersonDesc(wsk);
        }
        else
            break;
        ++i;
    }

    personalData person;

    person.remarks = NULL;
    ar[i] = person;

    return i;
}

int getOldestPerson(personalData data[])
{
    int oldestIndex = 0;

    if(data == NULL)
        return -1;

    int i = 0;

    while(data[i].remarks != NULL)
    {
        if(data[i].age > data[oldestIndex].age){
            oldestIndex = i;
        }
        ++i;
    }

    return oldestIndex;
}

int getSlimmestPerson(personalData data[], int len)
{
    int slimmestIndex = 0;

    if(data == NULL)
        return -1;

    for(int i = 0; i < len; ++i)
    {
        if(data[i].weight < data[slimmestIndex].weight)
            slimmestIndex = i;
    }
    return slimmestIndex;
}

void printInfo(personalData pd[], int idx, char *msgOk, char *msgbad)
{
    if(idx < 0)
        printf("%s", msgbad);
    else
    {
        printf("%s \n", msgOk);
        printf(" Name: %s\n Age: %d\n Weight: %0.1f\n Remarks: %s\n", pd[idx].name, pd[idx].age, pd[idx].weight, pd[idx].remarks);
    }
}
