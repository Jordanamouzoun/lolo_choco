/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** unit_test.c
*/

#include "../mini1.h"

Test(my_strlen, lengh_of_dtring)
{
    int a = my_strlen("papa");

    cr_assert_eq(a, 4);
}

Test(my_putstr, display_string)
{
    my_putstr("papa\n", '\0');
}

Test(my_putchar, display_char)
{
    my_putchar('a');
}

Test(comp, compare_two_string)
{
    int a = comp("papa", "0");

    cr_assert_eq(a, 0);
}

Test(my_strdup, duplicate_string)
{
    char *str = my_strdup("papa");

    cr_assert_str_eq("papa", str);
    free(str);
}
