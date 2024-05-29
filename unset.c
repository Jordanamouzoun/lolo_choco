/*
** EPITECH PROJECT, 2023
** BS shell
** File description:
** bs
*/

#include "mini1.h"

chaine_t *rec1;
chaine_t *prev;

int if_begin(char **cze)
{
    for (int j = 0; cze[j] != NULL; j++)
        if (!((cze[j][0] <= 'Z' && cze[j][0] >= 'A') ||
            (cze[j][0] <= 'z' && cze[j][0] >= 'a'))){
            putstr("set: Variable name must begin with a letter.\n");
            return 0;
        }
    return 1;
}

char *treat(char *st)
{
    int a = my_strlen(st);
    char *str = malloc(sizeof(char) * (a + 1));

    str = my_strcpy(str, st);
    while (a > 0 && str[a - 1] != '\t'){
        str[a - 1] = '\0';
        a--;
    }
    str[a - 1] = '\0';
    return str;
}

int suite(link_t *liste, chaine_t *rec1, chaine_t *prev, char *cze)
{
    if (comp(cze, treat(rec1->str)) == 1) {
        if (prev == NULL){
            liste->ch = rec1->next;
        } else {
            prev->next = rec1->next;
        }
        free(rec1);
        return 1;
    }
}

int del(link_t *liste, char *cze)
{
    if (liste == NULL)
        return 0;
    rec1 = liste->ch;
    prev = NULL;
    while (rec1 != NULL){
        if (suite(liste, rec1, prev, cze) == 1)
            return 0;
        prev = rec1;
        rec1 = rec1->next;
    }
    return 0;
}

void unset_cont(my_struc_t *stu, link_t *link2)
{
    if (!stu->list->ar[1]){
        write(1, "unset: Too few arguments.\n", 26);
        return;
    }
    if (set_er0(stu->list->ar) == 0)
        return;
    for (int i = 1; stu->list->ar[i] != NULL; i++)
        del(link2, stu->list->ar[i]);
}
