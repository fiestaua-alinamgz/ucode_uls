#include "uls.h"

void mx_colorize(struct stat forstat) {
    switch (forstat.st_mode & S_IFMT) {
        case S_IFBLK:
            mx_printstr(BG_CYAN);
            break;
        case S_IFREG:
            if (forstat.st_mode & S_IXUSR)
                mx_printstr(RED);
            break;
        case S_IFCHR:
            mx_printstr(BG_YELLOW);
            break;
        case S_IFDIR:
            mx_printstr(CYAN_BOLD);
            break;
        case S_IFIFO:
            mx_printstr(BG_CYAN);
            break;
        // case S_IFLNK:
        //     mx_printstr(MAGENTA);
            // break;
        // TODO:
        // case S_IFSOCK:
            // break;
        default:
            mx_printstr(MAGENTA);
            break;
    }
}

