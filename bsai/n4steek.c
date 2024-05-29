/*
** EPITECH PROJECT, 2024
** need4steek
** File description:
** need4steek
*/
#include "../include/my.h"

int start_simulation(void)
{
    char buffer[500];
    ssize_t n = 0;

    write(1, "start_simulation\n", 17);
    n = read(0, buffer, 500);
    write(2, buffer, n);
    write(1, "car_forward: 0.5\n", 17);
    n = read(0, buffer, 500);
    write(2, buffer, n);
    return 0;
}

int stop_simulation(char *buffer, char *str, char **arr)
{
    // ssize_t n = 0;

    // write(1, "stop_simulation\n", 17);
    // n = read(0, buffer, 500);
    // write(2, buffer, n);
    // free_arr(arr);
    // return 0;
}

int help_move(double left, double right, char *buffer, char **arr)
{
    if (left > right && atof(arr[19]) <= 200.0) {
        write(1, "wheels_dir: 0.50\n", 17);
        return 0;
    }
    if (left < right && atof(arr[19]) <= 200.0) {
        write(1, "wheels_dir: -0.50\n", 18);
        return 0;
    }
    if (left > right && atof(arr[19]) <= 1000.0) {
        write(1, "wheels_dir: 0.25\n", 17);
        return 0;
    }
    if (left < right && atof(arr[19]) <= 1000.0) {
        write(1, "wheels_dir: -0.25\n", 18);
        return 0;
    }
    return 1;
}

int move(double left, double right, char *buffer, char **arr)
{
    ssize_t n = 0;

    if (fabs(left - right) < 200.0 && atof(arr[19]) >= 500.0) {
        write(1, "car_forward: 0.3\n", 17);
        n = read(0, buffer, 500);
        write(2, buffer, n);
    }
    if (left <= 100.0) {
        write(1, "wheels_dir: 0.50\n", 17);
        return 0;
    }
    if (right <= 100.0) {
        write(1, "wheels_dir: -0.50\n", 18);
        return 0;
    }
    if (help_move(left, right, buffer, arr) == 1)
        write(1, "wheels_dir: 0\n", 14);
    return 0;
}

char **n4steek(char *buffer)
{
    ssize_t n = 0;
    char *str = NULL;
    char **arr = NULL;

    write(1, "get_info_lidar\n", 15);
    n = read(0, buffer, 500);
    write(2, buffer, n);
    arr = str_to_array(buffer, ":");
    if (atof(arr[15]) <= 1000.0) {
        write(1, "car_forward: 0.1\n", 17);
        n = read(0, buffer, 500);
        write(2, buffer, n);
    }
    return arr;
}
