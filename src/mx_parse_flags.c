#include "uls.h"

static inline void flags_error(char *str) {
    mx_printerr(ILLEGAL_OPTION);
    mx_printerr(str);
    mx_printerr(USAGE_START);
    mx_printerr(VALID_FLAGS);
    mx_printerr(USAGE_END);

    exit(1);
}

static inline void pick_unique_flags(const char *str, t_parse *p) {
    int is_valid = 0;
    char buf[2] = "";

    for (int i = 1; str[i]; i++) {
        if (str[i] != '1' && str[i] != 'l' && str[i] != 'C') {
            if (mx_get_char_index(p->flags, str[i]) >= 0) {
                continue;
            }
        }

        buf[0] = str[i];
        is_valid = mx_get_char_index(VALID_FLAGS, str[i]);

        if (is_valid < 0) {
            flags_error(buf);
        } else {
            mx_strcat(p->flags, buf);
        }
    }
}

int mx_parse_flags(int argc, char **argv, t_parse *p) {
    int i = 0;
    int f_len = mx_strlen(VALID_FLAGS);

    p->flags = mx_strnew(f_len);

    for (i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || !argv[i][1]) {
            return i;
        }
        if (mx_strcmp(argv[i], "--")) {
            pick_unique_flags(argv[i], p);
        } else {
            return (i + 1);
        }
    }

    return i;
}
