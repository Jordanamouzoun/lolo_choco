/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell2-jordan.amouzoun
** File description:
** redirection.c
*/

#include "mini1.h"

int redir_right(redir_t redir, my_struc_t *stu)
{
    struct stat statbuf;
    int fd = 0;
    char *str = mr_clean(redir.str);

    stat(str, &statbuf);
    if (S_ISDIR(statbuf.st_mode)) {
        help_write(stu, str);
        return 1;
    }
    if (strlen(str) == 0) {
        write(2, "Missing name for redirect.\n", 27);
        return 1;
    }
    fd = open(str, O_RDWR | O_CREAT | O_TRUNC,
    S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP | S_IWOTH);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return 0;
}

int redir_left(redir_t redir, my_struc_t *stu)
{
    int fd = 0;
    char *str = mr_clean(redir.str);

    if (access(str, F_OK) == -1) {
        write(2, str, strlen(str));
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    if (strlen(str) == 0) {
        write(2, "Missing name for redirect.\n", 27);
        return 1;
    }
    fd = open(str, O_RDONLY);
    dup2(fd, STDIN_FILENO);
    close(fd);
    return 0;
}

int redir_double_right(redir_t redir, my_struc_t *stu)
{
    struct stat statbuf;
    int fd = 0;
    char *str = mr_clean(redir.str);

    stat(str, &statbuf);
    if (S_ISDIR(statbuf.st_mode)) {
        help_write(stu, str);
        return 1;
    }
    if (strlen(str) == 0) {
        write(2, "Missing name for redirect.\n", 27);
        return 1;
    }
    fd = open(str, O_RDWR | O_CREAT | O_APPEND,
    S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP | S_IWOTH);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return 0;
}

int redir_double_left(redir_t redir, my_struc_t *stu)
{
    int fdp[2];
    char *str = mr_clean(redir.str);
    char *cmd;
    ssize_t n;

    pipe(fdp);
    if (strlen(str) == 0) {
        write(2, "Missing name for redirect.\n", 27);
        return 1;
    }
    while (1) {
        my_putstr("?", '\0');
        if (getline(&cmd, &n, stdin) == -1)
            break;
        if (compare(str, cmd, '\n') == 1)
            break;
        write(fdp[1], cmd, strlen(cmd));
    }
    closeup(fdp);
    return 0;
}

int redirection(my_struc_t *stu, char **arr, char **env, lis_t **link)
{
    int p = 0;
    char *str = redir(arr, stu, &p);
    char **ar = str_to_word_array(str);

    if (p - 1 == 0)
        return 1;
    if (strlen(mr_clean(str)) == 0) {
        write(2, "Invalid null command.\n", 22);
        stu->status = 1;
        return 0;
    }
    if (fork() == 0) {
        if (body_redirection(stu, ar, env, link) == 1) {
            stu->status = 1;
            return 0;
        }
    }
    wait(NULL);
    free(str);
    return 0;
}
