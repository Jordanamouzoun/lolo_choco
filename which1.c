/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** setenv.c
*/

#include "mini1.h"

int verif_compl(char **ptr, char *str, char *str2, int i)
{
    if (ptr[i][strlen(ptr[i])] == '/'){
            strcat(str2, str);
            if (access(str2, F_OK) == 0){
                putstr(str2);
                my_putchar('\n');
                return 0;
            }
        }
}

int verif_path(char **ptr, char *str)
{
    char *str2;

    for (int i = 0; ptr[i] != NULL; i++){
        str2 = my_strdup(ptr[i]);
        verif_compl(ptr, str, str2, i);
    }
}
