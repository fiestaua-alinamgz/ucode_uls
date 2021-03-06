#pragma once

// ====== defines ======
#define VALID_FLAGS "ACGT@aefhlr1"
#define BUF_SIZE 64

// ---- error msg -------
#define ILLEGAL_OPTION "uls: illegal option -- "
#define USAGE_START "\nusage: uls [-"
#define USAGE_END "] [file ...]\n"
#define ULS "uls: "
#define ADDR_ERR ": No such file or directory\n"
#define ACL_IGNORE "!#acl\n"
#define DENIED_ERR ": Permission denied\n"

// ---- colors -------
#define RESET_COLORS "\x1B[0m"
#define BOLD "\x1B[1m"

#define BLACK "\x1B[30m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN_BOLD "\x1B[1m\x1B[36m"
#define WHITE "\x1B[37m"

#define BG_YELLOW "\x1B[43m\x1B[34m"
#define BG_CYAN "\x1B[46m\x1B[34m"
#define BG_CYAN_BL "\x1B[46m\x1B[30m"
#define BG_RED "\x1B[41m\x1B[30m"


// ====== includes ======
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdbool.h>
#include <string.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include <sys/errno.h>
#include "libmx.h"


// ====== structs ======
typedef struct s_parce {
    char *str_nopermis;
    char *flags;
    char *path_pref;
    char **fullpath;
    char **addresses;
    char **files;
    char **dirs;
    char **invalid;
    char **nopermis;
    char **content_of_directory;
    int count_of_objects;
    int count_of_files;
    int count_of_dirs;
}              t_parse;

typedef struct s_sort {
    int d;
    int f;
    int i;
    int j;
    char *addr_sort;
}              t_sort;

typedef struct s_flags {
    bool lg_A;
    bool lg_C;
    bool lg_G;
    bool lg_a;
    bool lg_f;
    bool lg_l;
    bool lg_r;
    bool lg_1;
    bool lg_h;
    bool lg_e;
    bool lg_x;
    bool lg_T;
    bool just_files;
}              t_flags;

typedef struct s_forlong {
    int *max_len;
    int major;
    int minor;
    int count_of_device_files;
    int count_of_acl;
    char *suffix_size;
    char *fault_groupid;
    char *fault_userid;
    char *forhex;
}              t_forlong;

// ===================== funcs =====================
//  ----------------- char *  ------------------
char *mx_custom_nbr_to_hex(unsigned long nbr, t_forlong *p);
char *mx_fullpath(char *path, char *content);

//  ----------------- int ------------------
int mx_directory_info(t_parse *p, t_flags *f);
int mx_parse_flags(int argc, char **argv, t_parse *p);

//  ----------------- void ------------------
//  ---------- c ----------
void mx_check_acl_and_attributes(char *path);
void mx_colorize(struct stat forstat);
void mx_count_max_len(t_parse *p, t_forlong *forlong);
void mx_count_maxlen_files(t_parse *p, t_forlong *forlong);
void mx_count_maxlen_manydirs(t_parse *p, t_forlong *forlong);

//  ---------- f ----------
void mx_find_major_minor(int number, t_forlong *forlong);
void mx_float_to_char(float n, char *res, int afterpoint);
void mx_for_flag_h(t_forlong *forlong, int number);
void mx_free_malloc(t_parse *parse, int *rslt);

//  ---------- i ----------
void mx_init_parsing (t_parse *p);

//  ---------- l ----------
void mx_lexicographical_sort(t_parse *p);
void mx_line_output(t_parse *p, t_flags *f);
void mx_list_directory(t_parse *p, t_flags *f);
void mx_list_few_filedirs(t_parse *p, t_flags *f);
void mx_list_few_longdirs(t_forlong *forlong, t_parse *p, t_flags *f);

void mx_list_files(t_parse *p, t_flags *f);
void mx_list_longfile(t_forlong *forlong, t_parse *p, t_flags *f);
void mx_list_longdir(t_forlong *forlong, t_parse *p, t_flags *f);

//  ---------- o ----------
void mx_output_invalid_addr(t_parse *p);
void mx_output_ls(t_parse *p, t_flags *f);
void mx_output_permission_denied(t_parse *p);

//  ---------- p ----------
void mx_parse_input(int argc, char **argv, t_parse *p, t_flags *f);
void mx_parse_addresses(int i, int argc, char **argv, t_parse *p, t_flags *f);
void mx_print_acl(char *fullpath);
void mx_print_file_permissions(struct stat forstat);
void mx_print_in_line(t_parse *p, int first_ln, t_flags *f);
void mx_print_in_multiline(t_parse *p, int first_ln,
                           int max_width, t_flags *f);

void mx_print_lname(char *name, int max_len);
void mx_print_lname_right(char *name, int max_len);
void mx_print_lnumber(int value, int max_len);
void mx_print_manylongdirs(t_forlong *forlong,
                           t_parse *p, t_flags *f);
void mx_print_name_path(char *name_to_print, struct stat forstat,
                        char *fullpath, bool flag_G);
void mx_print_size_or_device(t_forlong *forlong, struct stat forstat,
                             t_flags *f);
void mx_print_time(struct stat forstat, t_flags *f);
void mx_print_type_of_file(struct stat forstat);
void mx_print_user_group(struct stat forstat, t_forlong *forlong);
void mx_print_xattr(char *fullpath);

//  ---------- s ----------
void mx_sort_addresses (t_parse *, t_flags *f, int size);
void mx_sort_alphabetically(char **arr, int left, int right, bool r_flag);
void mx_switch_flags(char *flags, t_flags *f);
