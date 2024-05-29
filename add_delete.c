/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** add.c
*/

#include "mini1.h"

int help_execution(int a, mini1_t *sh, charac_t *ch, my_struc_t *stu)
{
    sh->raca = malloc(500 * sizeof(char));
    strcpy(sh->raca, stu->args[a]);
    ch->str = strdup(stu->list->ar[0]);
    strcat(sh->raca, "/");
    strcat(sh->raca, ch->str);
}

int add_fin(void *data, char *str)
{
    lis_t **students = (lis_t **)data;
    lis_t *student = malloc(sizeof(lis_t));
    lis_t *temp;

    student->str = strdup(str);
    student->next = NULL;
    if ((*students) == NULL)
        (*students) = student;
    else {
        temp = (*students);
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = student;
    }
}

int help_del(lis_t *temp, lis_t *p, char *str, char c)
{
    while (temp->next != NULL && compare(str, (temp->next)->str, c) == 0)
        temp = temp->next;
    if (temp->next == NULL)
        return 0;
    if ((temp->next)->next != NULL) {
        p = temp->next;
        temp->next = (temp->next)->next;
        free(p);
    } else {
        p = temp->next;
        temp->next = NULL;
        free(p);
    }
}

int deleting(lis_t **list, char *str, char c)
{
    lis_t *temp;
    lis_t *p;

    if ((*list) != NULL) {
        if (compare(str, (*list)->str, c) == 1) {
            temp = (*list);
            (*list) = (*list)->next;
            free(temp);
        } else {
            temp = (*list);
            help_del(temp, p, str, c);
        }
    }
}

int detect_dir(my_struc_t *stu)
{
    struct stat statbuf;

    stat(stu->list->ar[0], &statbuf);
    if (statbuf.st_mode == __S_IFDIR) {
        if (count_slash(stu->list->ar[0]) == 0) {
            write(2, stu->list->ar[0], strlen(stu->list->ar[0]));
            write(2, ": Command not found.\n", 21);
            return 1;
        }
    }
    if (statbuf.st_mode == __S_IFDIR) {
        write(2, stu->list->ar[0], strlen(stu->list->ar[0]));
        write(2, ": Permission denied.\n", 21);
        stu->status = 1;
        return 1;
    }
    return 0;
}
