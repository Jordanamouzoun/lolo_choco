/*
** EPITECH PROJECT, 2023
** bsminish1
** File description:
** env.c
*/

#include "mini1.h"

int help_free(my_struc_t *stu, int a)
{
    for (; stu->list != NULL; stu->list = stu->list->next) {
        for (a = 0; stu->list->ar[a] != NULL; a++)
            free(stu->list->ar[a]);
        free(stu->list->ar);
    }
}

void free_list(lis_t *link)
{
    lis_t *temp;

    while (link != NULL) {
        temp = link;
        free(link->str);
        link = link->next;
        free(temp);
    }
}

void free_struct(my_struc_t *stu)
{
    int a;

    for (a = 0; stu->args[a] != NULL; a++)
        free(stu->args[a]);
    if (strlen(stu->str) != 0) {
        help_free(stu, a);
    }
    free(stu->args);
    free(stu);
}

void loop(char **env, my_struc_t *stu, lis_t *link, link_t *link2)
{
    char **argv = NULL;

    while (1) {
        if (mini1(argv, env, stu) == 1)
            break;
        execution(env, stu, link, link2);
    }
}

int main(int argc, char **argv, char **env)
{
    my_struc_t *stu = malloc(sizeof(my_struc_t));
    lis_t *link = NULL;
    link_t *link2 = NULL;
    int status = 0;
    mini2_t *temp = NULL;

    link2 = malloc(sizeof(link_t));
    link2->ch = NULL;
    aj_prime(link2);
    if (argc != 1)
        return 84;
    stu->status = 0;
    stu->list = NULL;
    envir(&link, env);
    declaration(stu, env);
    loop(env, stu, link, link2);
    status = stu->status;
    free_all(stu, temp, link);
    return status;
}
