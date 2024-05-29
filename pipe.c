/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell2-jordan.amouzoun
** File description:
** pipe.c
*/
#include "mini1.h"

int verif_pipe(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == '|')
            return 1;
    }
    return 0;
}

int header_pipe(my_struc_t *stu, char **arr)
{
    int a = 0;

    stu->ptr = malloc(sizeof(pip_t));
    stu->ptr->ar = NULL;
    stu->ptr->cmd = NULL;
    stu->ptr->fd = STDIN_FILENO;
    array_to_str(arr, stu->ptr->commande);
    if (verif_pipe(stu->ptr->commande) == 0)
        return 1;
    stu->ptr->ar = str_to_array(stu->ptr->commande, "|");
    for (int l = 0; stu->ptr->ar[l] != NULL; l++)
        if (strlen(mr_clean(stu->ptr->ar[l])) != 0)
            a++;
    if (a != count(stu->ptr->commande, '|')) {
        write(2, "Invalid null command.\n", 22);
        stu->status = 1;
        return 2;
    }
    return 0;
}

int body_pipe(my_struc_t *stu, int j, char **env, lis_t **link)
{
    if (j != 0) {
        dup2(stu->ptr->fd, STDIN_FILENO);
        close(stu->ptr->fd);
    }
    if (stu->ptr->ar[j + 1] != NULL) {
        dup2(stu->ptr->pipes[1], STDOUT_FILENO);
        close(stu->ptr->pipes[0]);
        close(stu->ptr->pipes[1]);
    }
    stu->ptr->cmd = str_to_word_array(stu->ptr->ar[j]);
    mini2(env, stu, link, stu->ptr->cmd);
    exit(0);
}

int tail_pipe(my_struc_t *stu, int j)
{
    if (j != 0)
        close(stu->ptr->fd);
    if (stu->ptr->ar[j + 1] != NULL) {
        close(stu->ptr->pipes[1]);
        stu->ptr->fd = stu->ptr->pipes[0];
    }
}

int pipeline(char **arr, char **env, my_struc_t *stu, lis_t **link)
{
    int h = header_pipe(stu, arr);

    if (h == 1)
        return 1;
    if (h == 2)
        return 0;
    for (int j = 0; stu->ptr->ar[j] != NULL; j++) {
        if (stu->ptr->ar[j + 1] != NULL)
            pipe(stu->ptr->pipes);
        if (fork() == 0)
            body_pipe(stu, j, env, link);
        tail_pipe(stu, j);
    }
    for (int j = 0; stu->ptr->ar[j] != NULL; j++)
        wait(NULL);
    return 0;
}
