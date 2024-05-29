/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell2-jordan.amouzoun
** File description:
** redirection.c
*/

#include "mini1.h"

int head_redir(my_struc_t *stu, redirec_t *redir, int *ai)
{
    int a = *ai;

    if (verif_redir(redir->commande[a], 0) == 1) {
        stu->redir[redir->l].c = redir->commande[a];
        stu->redir[redir->l].t = 1;
        if (redir->commande[a] == redir->commande[a + 1]) {
            stu->redir[redir->l].t = 2;
            a++;
        }
        redir->v = 1;
        a++;
    }
    *ai = a;
}

int body_redir(my_struc_t *stu, redirec_t *redir, int a)
{
    if (redir->v == 1) {
        stu->redir[redir->l].str[redir->c] = redir->commande[a];
        redir->c++;
        if (verif_redir(redir->commande[a + 1], 1) == 1 ||
        (redir->c > 1 && redir->commande[a] == ' ')) {
            stu->redir[redir->l].str[redir->c] = '\0';
            redir->c = 0;
            redir->l++;
            redir->v = 0;
        }
    }
    if (redir->v == 0 && verif_redir(redir->commande[a], 0) == 0) {
        redir->cmd[redir->b] = redir->commande[a];
        redir->b++;
    }
}

char *redir(char **arr, my_struc_t *stu, int *p)
{
    redirec_t *redir = malloc(sizeof(redirec_t));

    redir->l = 0;
    redir->v = 0;
    redir->c = 0;
    redir->b = 0;
    redir->cmd = malloc(500 * sizeof(char));
    array_to_str(arr, redir->commande);
    *p = count_redir(redir->commande);
    stu->redir = malloc(*p * sizeof(redir_t));
    for (int a = 0; redir->commande[a] != '\0'; a++) {
        head_redir(stu, redir, &a);
        body_redir(stu, redir, a);
    }
    stu->redir[redir->l].t = 84;
    redir->cmd[redir->b] = '\0';
    return redir->cmd;
}
