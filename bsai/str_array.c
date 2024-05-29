/*
** EPITECH PROJECT, 2024
** str_to_word_array.c
** File description:
** str_to_word_array.c
*/

#include "../include/my.h"

int count(char *str, char c)
{
    int l = 0;

    for (int a = 0; str[a] != 0; a++) {
        if (str[a] == c)
            l++;
    }
    return l;
}

char **str_to_array(char *str, char *sep)
{
    char *src = strdup(str);
    int a;
    char **arr = malloc((count(str, sep[0]) + 2) * sizeof(char *));
    char *tok = strtok(src, sep);

    for (a = 0; tok != NULL; a++) {
        arr[a] = strdup(tok);
        tok = strtok(NULL, sep);
    }
    arr[a] = NULL;
    return arr;
}

char *extract(char *str)
{
    char *res = malloc(strlen(str) * sizeof(char));
    int b = 0;
    int v = 0;

    for (int a = 0; str[a] != 0; a++) {
        if (str[a] == ':')
            v++;
        if (v == 3)
            a++;
        if (v == 35)
            break;
        if (v >= 3) {
            res[b] = str[a];
            b++;
        }
    }
    res[b] = 0;
    return res;
}
