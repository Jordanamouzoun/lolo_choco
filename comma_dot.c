/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell2-jordan.amouzoun
** File description:
** comma_dot.c
*/

#include "mini1.h"

int help_arr_to_list(char *str, my_struc_t *stu)
{
    if (strlen(mr_clean(str)) != 0)
        adding_fin(&stu->list, str);
}

char *mr_clean(char *src)
{
    char *str = malloc((strlen(src) + 5) * sizeof(char));
    int b = 0;
    int c = 0;

    for (c = strlen(src) - 1; src[c] == ' ' || src[c] == '\t'; c--);
    for (int a = 0; a <= c; a++)
        if (src[a] != ' ' && src[a] != '\t') {
            str[b] = src[a];
            b++;
        }
    str[b] = '\0';
    return str;
}

int adding_fin(void *data, char *str)
{
    mini2_t **students = (mini2_t **)data;
    mini2_t *student = malloc(sizeof(mini2_t));
    mini2_t *temp;

    student->ar = str_to_word_array(str);
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

int array_to_list(my_struc_t *stu)
{
    char *str = malloc(500 * sizeof(char));
    int b = 0;

    for (int a = 0; stu->str[a] != '\0'; a++) {
        if (stu->str[a] != ';') {
            str[b] = stu->str[a];
            b++;
        }
        if (stu->str[a] == ';') {
            str[b] = '\0';
            help_arr_to_list(str, stu);
            b = 0;
        }
    }
    str[b] = '\0';
    if (strlen(mr_clean(str)) != 0)
        adding_fin(&stu->list, str);
    b = 0;
    free(str);
}
