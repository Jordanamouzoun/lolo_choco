/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** unsetenv.c
*/

#include "mini1.h"

int error_setenv(my_struc_t *stu, char **path, int n)
{
    int y = 0;

    if (n != 2 && n != 3)
        return 1;
    for (int b = 1; b < n; b++) {
        if (disp(stu, path, b) == 0)
            y++;
    }
    if (y == 1)
        return 0;
    return 1;
}

int compare(char *str, char *env, char c)
{
    if (strlen(str) != strlen(env) && c == '\0')
        return 0;
    for (int a = 0; env[a] != c; a++) {
        if (str[a] != env[a])
            return 0;
        else
            continue;
    }
    return 1;
}

int my_len(char *str)
{
    int l;
    int c = 0;

    for (l = 0; str[l] != '\0'; l++)
        if (str[l] != '\t')
            c++;
    return c;
}

int my_unsetenv(my_struc_t *stu, lis_t **link, char **path)
{
    int a;
    char *src;

    for (a = 0; path[a] != NULL; a++);
    if (a == 1) {
        write(1, "unsetenv: Too few arguments.\n", 29);
        stu->status = 1;
    }
    for (a = 1; path[a] != NULL; a++) {
        deleting(link, path[a], '=');
    }
}
