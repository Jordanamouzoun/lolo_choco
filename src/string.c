/*
** EPITECH PROJECT, 2023
** bsminish1
** File description:
** string.c
*/

#include "../mini1.h"

int count_space(char *str)
{
    int i = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == ' ' || str[a] == '\t')
            i++;
    }
    return i + 1;
}

int count_double_dot(char *str)
{
    int i = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == ':')
            i++;
    }
    return i + 1;
}

char *my_strcat(char *dest, char const *src)
{
    int a = strlen(dest);
    int b;

    for (b = 0; src[b] != '\0'; b++) {
        dest[a] = src[b];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}

char *my_strcpy(char *dest, char *src)
{
    int a;

    for (a = 0; src[a] != '\0'; a++) {
        dest[a] = src[a];
    }
    dest[a] = '\0';
    return dest;
}
