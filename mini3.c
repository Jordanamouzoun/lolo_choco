/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell2-jordan.amouzoun
** File description:
** mini2.c
*/

#include "mini1.h"

void other_func(char **env, my_struc_t *stu, lis_t *link, link_t *link2)
{
    int a;

    if (comp("which", stu->list->ar[0]) == 1) {
        verif_path(stu->args, stu->list->ar[1]);
    }
    if (comp("repeat", stu->list->ar[0]) == 1) {
        a = atoi(stu->list->ar[1]);
        stu->list->ar[0] = strdup(stu->list->ar[2]);
        stu->list->ar[1] = NULL;
        stu->list->ar[2] = NULL;
        for (int i = 1; i < a; i++)
            mini2(env, stu, &link, stu->list->ar);
    }
}
