#include "uls.h"

void mx_init_parsing (t_parse *p) {
    p->right = 0;
    p->flags = NULL;
    p->target = NULL;
    p->addresses = NULL;
    p->files = NULL;
    p->dirs = NULL;
    p->ivalid_addr = NULL;
}