/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell2-jordan.amouzoun
** File description:
** mini2.c
*/

#include "mini1.h"

int execution(char **env, my_struc_t *stu, lis_t *link, link_t *link2)
{
    for (; stu->list != NULL; stu->list = stu->list->next) {
        array_to_str(stu->list->ar, stu->cmd);
        if (count(stu->cmd, '|') - 1 != 0 &&
        pipeline(stu->list->ar, env, stu, &link) == 0)
            continue;
        if (comp("set", stu->list->ar[0]) == 1) {
            set_cont(stu, link2);
            continue;
        }
        if (comp("unset", stu->list->ar[0]) == 1) {
            unset_cont(stu, link2);
            continue;
        }
        other_func(env, stu, link, link2);
        mini2(env, stu, &link, stu->list->ar);
    }
}

int free_all(my_struc_t *stu, mini2_t *temp, lis_t *link)
{
    free_struct(stu);
    free_list(link);
}

char *array_to_str(char **array, char *str)
{
    strcpy(str, array[0]);
    strcat(str, " ");
    for (int a = 1; array[a] != NULL; a++) {
        strcat(str, array[a]);
        strcat(str, " ");
    }
    return str;
}

int help_write(my_struc_t *stu, char *str)
{
    write(2, str, strlen(str));
    write(2, ": Is a directory.\n", 18);
    stu->status = 1;
}

int closeup(int fdp[2])
{
    dup2(fdp[0], STDIN_FILENO);
    close(fdp[0]);
    close(fdp[1]);
}
