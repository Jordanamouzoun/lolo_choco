/*
** EPITECH PROJECT, 2024
** array_free.c
** File description:
** array_free.c
*/

#include "../include/my.h"
int free_arr(char **arr)
{
    int a = 0;

    for (a = 0; arr[a] != NULL; a++) {
        free(arr[a]);
    }
    free(arr[a]);
    free(arr);
}

int my_free(char *buffer, char *str, char **arr)
{
    ssize_t n = 0;

    n = read(0, buffer, 200);
    write(2, buffer, n);
    free_arr(arr);
    return 0;
}
