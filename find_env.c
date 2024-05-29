/*
** EPITECH PROJECT, 2023
** bsminish1
** File description:
** find_env.c
*/

#include "mini1.h"

int free_str(mini1_t *sh, charac_t *ch)
{
    free(sh);
    free(ch);
}

int show(char **env, my_struc_t *stu)
{
    mini1_t *sh = malloc(sizeof(mini1_t));
    charac_t *ch = malloc(sizeof(charac_t));
    int a = 0;

    for (a = 0; stu->args[a] != NULL; a++) {
        if (my_access(stu->args[a], stu->list->ar[0]) == 1 ||
        access(stu->list->ar[0], X_OK) == 0) {
            help_execution(a, sh, ch, stu);
            break;
        }
    }
    if (stu->args[a] == NULL)
        return 1;
    return (helping_show(env, stu, sh, ch));
}

int count_double_dot(char *str)
{
    int i = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == ':')
            i++;
    }
    return i + 1;
}

int find_env(char *str, char *src, int *i)
{
    int a;

    for (a = 0; src[a] != '\0'; a++) {
        if (str[a] == src[a])
            continue;
        else
            return 0;
    }
    *i = a + 1;
    return 1;
}

char *my_getenv(char *str, char **env)
{
    int i = 0;

    for (int a = 0; env[a] != NULL; a++) {
        if (find_env(env[a], str, &i) == 1) {
            return env[a] + i;
        }
    }
}
