/*
** EPITECH PROJECT, 2023
** B-PSU-200-COT-2-1-minishell1-jordan.amouzoun
** File description:
** test_string.c
*/

#include "../mini1.h"

Test(count_space, count_space_in_string)
{
    int a = count_space("papa maman");

    cr_assert_eq(a, 2);
}

Test(count_double_dot, count_dot_in_string)
{
    int a = count_double_dot("papa:maman");

    cr_assert_eq(a, 2);
}

Test(my_strcat, transform_string_in_one)
{
    char str[11] = "papa";

    my_strcat(str, " maman");
    cr_assert_str_eq("papa maman", str);
}

Test(my_strcpy, copy_strig)
{
    char *str = "papa";
    char src[5];

    my_strcpy(src, str);
    cr_assert_str_eq(src, str);   
}
