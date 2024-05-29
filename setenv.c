/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** setenv.c
*/

#include "mini1.h"

int envir(lis_t **link, char **env)
{
    for (int j = 0; env[j] != NULL; j++) {
        add_fin(link, env[j]);
    }
}

int my_setenv(char *name, char *value, lis_t **link)
{
    char *str = strdup(name);

    str = strcat(str, "=");
    str = strcat(str, value);
    add_fin(link, str);
}

int display_env(my_struc_t *stu, lis_t **link)
{
    lis_t *temp;

    temp = (*link);
    while (temp != NULL) {
        my_putstr(temp->str, '\0');
        my_putchar('\n');
        temp = temp->next;
    }
}

int verification(lis_t **link, char **path, int a)
{
    lis_t *temp;
    char *str;

    if (a == 2 || a == 3) {
        strcpy(str, path[1]);
        strcat(str, "=");
    }
    if (a == 2)
        strcat(str, "");
    if (a == 3)
        strcat(str, path[2]);
    temp = (*link);
    while (temp != NULL) {
        if (compare(path[1], temp->str, '=') == 1) {
            temp->str = strdup(str);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int set_my_setenv(char **path, lis_t **link, my_struc_t *stu)
{
    int a;

    for (a = 0; path[a] != NULL; a++);
    if (error_setenv(stu, path, a) == 0)
        return 0;
    if (a == 1) {
        display_env(stu, link);
    }
    if (a == 2 || a == 3) {
        if (verification(link, path, a) == 1)
            return 0;
    }
    if (a == 2)
        my_setenv(path[1], "", link);
    if (a == 3)
        my_setenv(path[1], path[2], link);
    if (a >= 4) {
        my_putstr("setenv: Too many arguments.\n", '\0');
        stu->status = 1;
    }
}
