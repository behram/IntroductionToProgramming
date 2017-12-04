#include "Config.h"

config newConfig() {
    config c;

    c.arg1 = "";
    c.arg2 = "";
    
    return c;
}

void setConfig(config *conf, int argc, char * argv[]) {

    int non_flags_arguments = 0;
    
    while (optind < argc) {

            non_flags_arguments++;

            switch (non_flags_arguments) {
                case 1:
                    conf->arg1 = argv[optind];
                    break;

                case 2:
                    conf->arg2 = argv[optind];
                    break;
            }

            optind++;
    }

    if (non_flags_arguments == 1) {
        conf->rm = lineBegins;
    }
    else if (non_flags_arguments == 2) {
        if (_is_dash(conf->arg1)) {
            conf->rm = firstWordBeginsWith;
        }
        else if (_is_dash(conf->arg2)) {
            conf->rm = firstWordEndsWith;
        }
        else {
            conf->rm = lineBeginsInRange;
        }
    }
}

bool _is_dash(const char *str) {
    return (strlen(str) == 1 && str[0] == '-');
}
