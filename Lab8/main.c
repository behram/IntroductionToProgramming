#include "Functions.h"

int main()
{
    personalData data[10];

    int len = readData(data, sizeof(data)/sizeof(personalData));
    int idx;
    char *msgBad = "\nNo available data\n";

    idx = getOldestPerson(data);
    printInfo(data, idx, "\nOldest person\n", msgBad);

    idx = getSlimmestPerson(data, len);
    printInfo(data, idx, "\nSlimmest person\n", msgBad);

    puts("\nHappy Days!");

    return 0;
}
