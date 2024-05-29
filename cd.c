/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** cd.c
*/

#include "mini1.h"

void help_cd(char **path, my_struc_t *stu)
{
    my_putstr(path[1], '\0');
    my_putstr(": Not a directory.\n", '\0');
    stu->status = 1;
}

int error_cd(char **path, int n, my_struc_t *stu)
{
    if (n >= 3) {
        my_putstr("cd: Too many arguments.\n", '\0');
        stu->status = 1;
    }
    if (n == 2) {
        if (comp(path[1], "-") == 1 || comp(path[1], "~") == 1)
            return 0;
    }
    if (n == 2 && access(path[1], F_OK) == -1) {
        my_putstr(path[1], '\0');
        my_putstr(": No such file or directory.\n", '\0');
        stu->status = 1;
    }
}

int my_cd(char **path, my_struc_t *stu, char **env)
{
    int a;
    int len = strlen(cd);
    char str[1024];

    if (len == 0)
        getcwd(cd, sizeof(cd));
    getcwd(str, sizeof(str));
    for (a = 0; path[a] != NULL; a++);
    error_cd(path, a, stu);
    if (a == 1)
        chdir(my_getenv("HOME", env));
    if (a == 2 && (comp(path[1], "~") == 1 || comp(path[1], " ") == 1))
        chdir(my_getenv("HOME", env));
    if (a == 2 && comp(path[1], "~") == 0)
        if (chdir(path[1]) == -1 && errno == ENOTDIR)
            help_cd(path, stu);
    if (a == 2 && comp(path[1], "-") == 1)
        chdir(cd);
    strcpy(cd, str);
}
