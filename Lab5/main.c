#include <stdio.h>

#include "Config.h"
#include "Selectors.h"

int main(int argc, char * argv[]) {
    config configuration = newConfig();
    setConfig(&configuration, argc, argv);

    switch (configuration.rm) {
        case rmLineBegins:
            run_with(lineBegins, &configuration);
            break;

        case rmLineBeginsInRange:
            run_with(lineBeginsInRange, &configuration);
            break;

        case rmFirstWordBeginsWith:
            run_with(firstWordBeginsWith, &configuration);
            break;
        case rmFirstWordEndsWith:
            run_with(firstWordEndsWith, &configuration);
            break;
    }

    return 0;
}
