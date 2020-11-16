#include "uls.h"

static inline bool is_flag(const char *str) {
    bool rslt = str[0] == '-' && (mx_strlen(str) > 1) ? 1 : 0;
    return rslt;
}

static inline void pick_unique_flags(const char *str, t_parse *p) {
char buf[2] = {};

for (int i = 1; str[i]; i++) {
	if(mx_get_char_index(p->flags, str[i]) < 0) {
		buf[0] = str[i];
		mx_strjoin(p->flags, buf);
	}
}

void mx_parse_input(int argc, char **argv, t_parse *p) {
	int i = 0;
	int j = 0;
	int k = 0;

	if (is_flag(argv[1])) {
		for(j = 1; j < argc && is_flag(argv[j]); j++) {
			pick_unique_flags(argv[j], p);
        }
    }
mx_printstr("\n ==== check ===== \n");
mx_printstr("argc: ");
mx_printint(argc);
mx_printstr("\nj: ");
mx_printint(j);
mx_ptintstr("\n argc - j: ");
mx_printint((argc-j));
mx_printstr("\n==================\n\n");
    p->addresses = (char**)malloc(sizeof(char*) * (argc - j));
	for (i = 0; i <= (argc - j); i++) {
		p->addresses[i] = NULL;
	}
	for(; j < argc; j++) {
		p->addresses[k++] = mx_strdup(argv[j]);
	}
}