/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** setenv.c
*/

#include "mini1.h"

void set_cont(my_struc_t *stu, link_t *link2)
{
    if (!stu->list->ar[1]){
        disp_set(link2);
        return;
    }
    if (set_er0(stu->list->ar) == 0)
        return;
    if (if_begin(stu->list->ar) == 0)
        return;
    if (set_er2(stu->list->ar) == 0)
        return;
    for (int i = 1; stu->list->ar[i] != NULL; i++)
        add_set(link2, stu->list->ar[i]);
}

int set_er0(char **cze)
{
    for (int j = 0; cze[j] != NULL; j++)
        if (set_er01(cze, j) == 0)
            return 0;
    return 1;
}

int set_er2(char **cze)
{
    for (int j = 0; cze[j] != NULL; j++)
        if (set_er02(cze, j) == 0)
            return 0;
    return 1;
}

void putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        write(1, &str[i], 1);
    }
}
