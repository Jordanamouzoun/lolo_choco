/*
** EPITECH PROJECT, 2023
** bsai
** File description:
** main.c
*/
#include "../include/my.h"
#include "main.h"
int count2(char **arr)
{
    int c = 0;

    for (int i = 0; arr[i] != NULL; i++)
        c++;
    return c;
}

int check_str(char *str)
{
    if (str[2] == '0')
        exit(1);
    return 0;
}

int main(int argc, char **argv)
{
    char buffer[500];
    ssize_t n = 0;
    char *str = NULL;
    char **arr = NULL;
    double left = 0;
    double right = 0;
    int c = 0;

    start_simulation();
    while (1) {
        arr = n4steek(buffer);
        if (c != 0 && count2(arr) >= 36)
            check_str(arr[36]);
        left = atof(arr[3]);
        right = atof(arr[34]);
        move(left, right, buffer, arr);
        my_free(buffer, str, arr);
        c++;
    }
}
