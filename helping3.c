/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** helping3.c
*/

#include "mini1.h"

int disp(my_struc_t *stu, char **path, int b)
{
    for (int a = 0; path[b][a] != '\0'; a++) {
        if (help_setenv(stu, path, a, b) == 0) {
            stu->status = 1;
            return 0;
        }
    }
    return 1;
}

char *cpy(char *dest, char *src, int i, int f)
{
    int n = 0;

    for (int a = i; a <= f; a++) {
        dest[n] = src[a];
        n++;
    }
    dest[n] = '\0';
    return dest;
}

char *mr_cleaner(char *str)
{
    char *src = malloc(strlen(str) * sizeof(char));
    int b = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == ' ' && a == 0)
            a++;
        if (str[a + 1] == '\0' && str[a] == ' ')
            a++;
        src[b] = str[a];
        b++;
    }
    src[b] = '\0';
    return src;
}

int count(char *str, char c)
{
    int i = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == c)
            i++;
    }
    return i + 1;
}

char **str_to_array(char *str, char *sep)
{
    char *src = strdup(str);
    int a;
    char **arr = malloc((count(str, sep[0]) + 1) * sizeof(char *));
    char *tok = strtok(src, sep);

    for (a = 0; tok != NULL; a++) {
        arr[a] = strdup(tok);
        tok = strtok(NULL, sep);
    }
    arr[a] = NULL;
    return arr;
}
