/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** setenv.c
*/

#include "mini1.h"
chaine_t *mat;
chaine_t *temp;

char *inttostr(int num)
{
    char *str = malloc(12);
    char *str2 = str + 10;

    *str2 = '\0';
    while (num != 0){
        --str2;
        *str2 = '0' + num % 10;
        num /= 10;
    }
    return str2;
}

char aj_prime(link_t *link)
{
    char *str = my_strdup("PID=");

    strcat(str, inttostr(getpid()));
    add_set(link, str);
    str = strdup("GID=");
    strcat(str, inttostr(getgid()));
    add_set(link, str);
    str = my_strdup("PGID=");
    strcat(str, inttostr(getpgid(0)));
    add_set(link, str);
}

char *replace(char *str)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '='){
            str[i] = '\t';
            c++;
        }
    }
    if (c == 0)
        str[my_strlen(str)] = '\t';
    return str;
}

int add_set(link_t *liste, char *str)
{
    chaine_t *mat = malloc(sizeof(chaine_t));
    chaine_t *temp = liste->ch;

    mat->str = my_strdup(replace(str));
    if (temp == NULL){
        mat->next = liste->ch;
        liste->ch = mat;
    } else {
        mat->next = NULL;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = mat;
    }
}

void disp_set(link_t *liste)
{
    chaine_t *mat = malloc(sizeof(chaine_t));

    if (liste == NULL){
        return;
    }
    mat = liste->ch;
    while (mat != NULL){
        write(1, mat->str, my_strlen(mat->str));
        my_putchar('\n');
        mat = mat->next;
    }
    return;
}
