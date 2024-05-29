/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** setenv.c
*/

#include "mini1.h"

int set_er01(char **cze, int j)
{
    for (int i = 0; cze[j][i] != '\0'; i++)
        if (cze[j][i] == '(' || cze[1][i] == ')'){
            write(1, "Too many ", 9);
            write(1, &cze[j][i], 1);
            write(1, "'s.\n", 4);
            return 0;
        }
    return 1;
}

int set_er02(char **cze, int j)
{
    for (int i = 0; cze[j][i] != '\0'; i++)
        if (!((cze[j][i] <= 'Z' && cze[j][i] >= 'A') ||
            (cze[j][i] <= 'z' && cze[j][i] >= 'a') ||
            (cze[j][i] <= '9' && cze[j][i] >= '0') ||
            cze[j][i] == '_' || cze[j][i] == '.' ||
            cze[j][i] == '=')){
            putstr("set: Variable name must contain ");
            putstr("alphanumeric characters.\n");
            return 0;
        }
    return 1;
}
