/*
** EPITECH PROJECT, 2023
** bsminish1
** File description:
** mini1.h
*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#ifndef MY_H
    #define MY_H
typedef struct redirec {
    char commande[500];
    int l;
    int v;
    int c;
    int b;
    char *cmd;
} redirec_t;
typedef struct pip {
    int pipes[2];
    char commande[500];
    pid_t child;
    char **ar;
    char **cmd;
    int fd;
} pip_t;
typedef struct redir {
    char str[500];
    char c;
    int t;
} redir_t;
typedef struct mini2 {
    char **ar;
    struct mini2 *next;
}mini2_t;
typedef struct mini1 {
    struct dirent *enter;
    char *raca;
    DIR *rep;
    int f;
}mini1_t;
typedef struct charac {
    char *str;
    char *args;
    char **argv;
    char **env;
}charac_t;
typedef struct entier {
    int l;
    int c;
}entier_t;
typedef struct my_struc {
    char *str;
    int nombre;
    char *src;
    char **args;
    mini2_t *list;
    int z;
    int f;
    int status;
    ssize_t n;
    int v;
    pip_t *ptr;
    redir_t *redir;
    char cmd[500];
    char cmde[500];
}my_struc_t;
typedef struct link_t {
    char *str;
    struct link_t *next;
} lis_t;
typedef struct chaine {
    char *str;
    struct chaine *next;
}chaine_t;

typedef struct {
    chaine_t *ch;
}link_t;
static char cd[1024];
static int global;
int verif_path(char **ptr, char *str);
void other_func(char **env, my_struc_t *stu, lis_t *link, link_t *link2);
int if_begin(char **cze);
int set_er01(char **cze, int j);
int set_er02(char **cze, int j);
int del(link_t *liste, char *cze);
void unset_cont(my_struc_t *stu, link_t *link2);
int set_er0(char **cze);
void putstr(char *str);
int set_er2(char **cze);
void set_cont(my_struc_t *stu, link_t *link2);
int my_len(char *str);
int count_slash(char *str);
char *found_dir(my_struc_t *stu);
int verif_alph(char c, int a);
int detect_dir(my_struc_t *stu);
int disp(my_struc_t *stu, char **path, int b);
int path_handling(my_struc_t *stu, char **env);
int help_show(char **env, my_struc_t *stu, mini1_t *sh);
int error_setenv(my_struc_t *stu, char **path, int n);
int help_setenv(my_struc_t *stu, char **path, int a, int n);
int help_execution(int a, mini1_t *sh, charac_t *ch, my_struc_t *stu);
int my_unsetenv(my_struc_t *stu, lis_t **link, char **path);
int compare(char *str, char *env, char c);
int deleting(lis_t **list, char *str, char c);
int display_env(my_struc_t *stu, lis_t **link);
int envir(lis_t **link, char **env);
int my_setenv(char *name, char *value, lis_t **link);
int add_fin(void *data, char *str);
int declaration(my_struc_t *stu, char **env);
int mini1(char **argv, char **env, my_struc_t *stu);
int mini2(char **env, my_struc_t *stu, lis_t **link, char **arr);
char *my_strcpy(char *dest, char *src);
int my_strlen(char *str);
char *my_strcat(char *dest, char const *src);
int my_cd(char **path, my_struc_t *stu, char **env);
void my_putchar(char c);
int my_putstr(char *str, char c);
int comp(char *str, char *src);
char *my_strdup(char *str);
char **my_str_to_word_array(char *str);
int show(char **env, my_struc_t *stu);
int count_double_dot(char *str);
int set_my_setenv(char **path, lis_t **link, my_struc_t *stu);
int find_env(char *str, char *src, int *i);
char *my_getenv(char *str, char **env);
char **str_to_word_array(char *str);
int count_space(char *str);
int help_exe(mini1_t *sh, char **argv, char **env, charac_t *ch);
int adding_fin(void *data, char *str);
int array_to_list(my_struc_t *stu);
int execution(char **env, my_struc_t *stu, lis_t *link, link_t *link2);
int free_all(my_struc_t *stu, mini2_t *temp, lis_t *link);
int help_free(my_struc_t *stu, int a);
void free_list(lis_t *link);
void free_struct(my_struc_t *stu);
int help_arr_to_list(char *str, my_struc_t *stu);
char *mr_clean(char *src);
char *cpy(char *dest, char *src, int i, int f);
char *mr_cleaner(char *str);
int count(char *str, char c);
char **str_to_array(char *str, char *sep);
char *array_to_str(char **array, char *str);
int pipeline(char **arr, char **env, my_struc_t *stu, lis_t **link);
int verif_pipe(char *str);
int header_pipe(my_struc_t *stu, char **arr);
int body_pipe(my_struc_t *stu, int j, char **env, lis_t **link);
int tail_pipe(my_struc_t *stu, int j);
int verif_redir(char c, int v);
int count_redir(char *str);
char *redir(char **arr, my_struc_t *stu, int *p);
int head_redir(my_struc_t *stu, redirec_t *redir, int *ai);
int body_redir(my_struc_t *stu, redirec_t *redir, int a);
int redir_right(redir_t redir, my_struc_t *stu);
int redir_left(redir_t redir, my_struc_t *stu);
int redirection(my_struc_t *stu, char **arr, char **env, lis_t **link);
int body_redirection(my_struc_t *stu, char **ar, char **env, lis_t **link);
int redir_double_right(redir_t redir, my_struc_t *stu);
int my_access(char *args, char *arr);
int helping_show(char **env, my_struc_t *stu, mini1_t *sh, charac_t *ch);
int free_str(mini1_t *sh, charac_t *ch);
int help_write(my_struc_t *stu, char *str);
int redir_double_left(redir_t redir, my_struc_t *stu);
int closeup(int fdp[2]);
int add_set(link_t *liste, char *str);
void disp_set(link_t *liste);
char aj_prime(link_t *link);
#endif
