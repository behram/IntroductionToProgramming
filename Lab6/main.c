#include <stdio.h>
#include <unistd.h>

#include "RunningModes.h"
#include "LineMethods.h"

int main(int argc, char * argv[]) {
    char option;
    option = argv[1][1];

    switch (option) {
        case 'l': case 'L':
            runWith(change2LowerCase);
            break;

        case 'u': case 'U':
            runWith(change2UpperCase);
            break;

        case 'c': case 'C':
            runWith(switchCase);
            break;

        case 'n': case 'N':
            runWith(makeNames);
            break;

        default:
            runWith(change2UpperCase);
            break;
    }
    return 0;
}