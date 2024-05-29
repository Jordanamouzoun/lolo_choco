/*
** EPITECH PROJECT, 2023
** bsminish1
** File description:
** seg.c
*/

#include "../mini1.h"

int strlen(char *str)
{
    int a = 0;

    for (a; str[a] != '\0'; a++);
    return a;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str, char c)
{
    for (int a = 0; str[a] != c; a++)
        my_putchar(str[a]);
}

int comp(char *str, char *src)
{
    if (strlen(str) != strlen(src))
        return 0;
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] != src[a])
            return 0;
        else
            continue;
    }
    return 1;
}

char *my_strdup(char *str)
{
    char *src = malloc((strlen(str) + 1) * sizeof(char));
    int a;

    for (a = 0; str[a] != '\0'; a++) {
        src[a] = str[a];
    }
    src[a] = '\0';
    return src;
}
