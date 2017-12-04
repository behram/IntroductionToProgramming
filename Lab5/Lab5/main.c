#include <stdio.h>

#include "Config.h"
#include "Selectors.h"

int main(int argc, char * argv[]) {
    config configuration = newConfig();
    setConfig(&configuration, argc, argv);

    switch (configuration.rm) {
        case rm_line_begins:
            run_with(line_begins, &configuration);
            break;

        case rm_line_begins_in_range:
            run_with(line_begins_in_range, &configuration);
            break;

        case rm_first_word_begins_with:
            run_with(first_word_begins_with, &configuration);
            break;
        case rm_first_word_ends_with:
            run_with(first_word_ends_with, &configuration);
            break;
    }

    return 0;
}
