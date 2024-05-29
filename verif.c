/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell2-jordan.amouzoun
** File description:
** verif.c
*/

#include "mini1.h"

int verif_redir(char c, int v)
{
    if (c == '>' || c == '<')
        return 1;
    if (v == 1) {
        if (c == '\0')
            return 1;
    }
    return 0;
}

int count_redir(char *str)
{
    int n = 0;

    for (int l = 0; str[l] != '\0'; l++) {
        if (verif_redir(str[l], 0) == 1)
            n++;
    }
    return n + 1;
}

int my_access(char *args, char *arr)
{
    struct dirent *enter;
    DIR *rep;

    rep = opendir(args);
    if (rep == NULL)
        return 0;
    enter = readdir(rep);
    while (enter != NULL) {
        if (comp(enter->d_name, arr) == 1)
            return 1;
        enter = readdir(rep);
    }
    closedir(rep);
    return 0;
}
