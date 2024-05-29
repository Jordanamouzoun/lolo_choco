/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <math.h>

int free_arr(char **arr);
char *extract(char *str);
int start_simulation(void);
int stop_simulation(char *buffer, char *str, char **arr);
int move(double left, double right, char *buffer, char **arr);
int my_free(char *buffer, char *str, char **arr);
char **n4steek(char *buffer);
int count(char *str, char c);
char **str_to_array(char *str, char *sep);
int help_move(double left, double right, char *buffer, char **arr);

#endif
