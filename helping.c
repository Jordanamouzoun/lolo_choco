/*
** EPITECH PROJECT, 2023
** bsminish1
** File description:
** helping.c
*/

#include "mini1.h"

int declaration(my_struc_t *stu, char **env)
{
    stu->src = my_getenv("PATH", env);
    stu->args = my_str_to_word_array(stu->src);
    for (; stu->list != NULL; stu->list = stu->list->next)
        stu->list->ar = NULL;
    stu->z = 0;
    stu->n = 0;
}

int help_mini2(my_struc_t *stu, lis_t **link, char **env)
{
    if (comp("cd", stu->list->ar[0]) == 1) {
        my_cd(stu->list->ar, stu, env);
        return 1;
    }
    if (comp("setenv", stu->list->ar[0]) == 1) {
        set_my_setenv(stu->list->ar, link, stu);
        return 1;
    }
    if (comp("env", stu->list->ar[0]) == 1) {
        display_env(stu, link);
        return 1;
    }
    if (comp("unsetenv", stu->list->ar[0]) == 1) {
        my_unsetenv(stu, link, stu->list->ar);
        return 1;
    }
    return 0;
}

char *display_prompt(void)
{
    char str[1024];

    getcwd(str, sizeof(str));
    my_putstr("\033[34;01m[", '\0');
    my_putstr(str + 1, '\0');
    my_putstr("]$>\033[00m", '\0');
}

int mini1(char **argv, char **env, my_struc_t *stu)
{
    display_prompt();
    stu->z = 0;
    if (getline(&stu->str, &stu->n, stdin) == -1) {
        my_putstr("exit\n", '\0');
        return 1;
    }
    for (stu->nombre = 0; stu->str[stu->nombre] != '\0'; stu->nombre++);
    stu->str[stu->nombre - 1] = '\0';
    if (comp("exit", stu->str) == 1) {
        exit(0);
    }
    if (strlen(stu->str) == 0)
        return 0;
    array_to_list(stu);
    return 0;
}

int mini2(char **env, my_struc_t *stu, lis_t **link, char **arr)
{
    stu->list->ar = arr;
    array_to_str(arr, stu->cmde);
    if (count_redir(stu->cmde) - 1 != 0)
        if (redirection(stu, stu->list->ar, env, link) == 0)
                return 0;
    if (help_mini2(stu, link, env) == 1)
        return 0;
    if (detect_dir(stu) == 1)
        return 0;
    stu->z = show(env, stu);
    if (stu->z == 1) {
        write(2, strcat(stu->list->ar[0], ": Command not found.\n"),
        strlen(stu->list->ar[0]) + 21);
    }
    if (stu->z == 1)
        stu->status = 1;
}
