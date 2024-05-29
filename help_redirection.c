/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell2-jordan.amouzoun
** File description:
** help_redirection.c
*/

#include "mini1.h"

int body_redirection(my_struc_t *stu, char **ar, char **env, lis_t **link)
{
    for (int a = 0; stu->redir[a].t != 84; a++) {
        if (stu->redir[a].c == '>' && stu->redir[a].t == 1 &&
        redir_right(stu->redir[a], stu) == 1)
            return 1;
        if (stu->redir[a].c == '>' && stu->redir[a].t == 2 &&
        redir_double_right(stu->redir[a], stu) == 1)
            return 1;
        if (stu->redir[a].c == '<' && stu->redir[a].t == 1 &&
        redir_left(stu->redir[a], stu) == 1)
            return 1;
        if (stu->redir[a].c == '<' && stu->redir[a].t == 2 &&
        redir_double_left(stu->redir[a], stu) == 1)
            return 1;
    }
    mini2(env, stu, link, ar);
    exit(0);
    return 0;
}
