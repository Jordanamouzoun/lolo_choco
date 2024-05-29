/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** helping2.c
*/

#include "mini1.h"

int verif_alph(char c, int a)
{
    if (c >= 'a' && c <= 'z')
        return 0;
    if (c >= 'A' && c <= 'Z')
        return 0;
    if (a == 1 && c >= '0' && c <= '9')
        return 0;
    if (a == 1 && c == '_')
        return 0;
    return 1;
}

int help_setenv(my_struc_t *stu, char **path, int a, int n)
{
    for (int j = 0; path[n][j] != '\0'; j++) {
        if (path[n][j] == '(') {
            write(1, "Too many ('s.\n", 14);
            return 0;
        }
        if (path[n][j] == ')') {
            write(1, "Too many )'s.\n", 14);
            return 0;
        }
    }
    if (n == 1 && verif_alph(path[1][0], 0) == 1) {
        write(1, "setenv: Variable name must begin with a letter.\n", 48);
        return 0;
    }
    if (n == 1 && verif_alph(path[1][a], 1) == 1) {
        write(1, "setenv: Variable name must contain alphanumeric ", 48);
        write(1, "characters.\n", 12);
        return 0;
    }
    return 1;
}

int help_show(char **env, my_struc_t *stu, mini1_t *sh)
{
    stu->f = fork();
    if (access(stu->list->ar[0], X_OK) == 0 && stu->f == 0) {
        if (execve(stu->list->ar[0], stu->list->ar, env) && errno == ENOEXEC) {
            write(2, stu->list->ar[0], strlen(stu->list->ar[0]));
            write(2, ": Exec format error. Wrong Architecture.\n", 41);
            stu->status = 1;
        }
        exit(0);
    }
    if (access(sh->raca, X_OK) == 0 && stu->f == 0) {
        if (execve(sh->raca, stu->list->ar, env) && errno == ENOEXEC) {
            write(2, sh->raca, strlen(sh->raca));
            write(2, ": Exec format error. Wrong Architecture.\n", 41);
            stu->status = 1;
        }
        exit(0);
    }
    wait(&stu->status);
}

int count_slash(char *str)
{
    int n;
    int i = 0;

    for (n = 0; str[n] != '\0'; n++) {
        if (str[n] == '/')
            i++;
    }
    return i;
}

int helping_show(char **env, my_struc_t *stu, mini1_t *sh, charac_t *ch)
{
    help_show(env, stu, sh);
    if (stu->status == 139 || stu->status == 11) {
        write(1, "Segmentation fault\n", 19);
        stu->status = 139;
    } else
        stu->status = WEXITSTATUS(stu->status);
    return 0;
}
