/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** test.c
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(strlen, count_the_characters_in_a_string)
{
    const char *test_str = "Len";
    const char *str_test = "";
    const char *the_test = "it_is_a_test_to_show";

    cr_assert_eq(strlen(str_test), 0, "Error for str_test !");
    cr_assert_eq(strlen(test_str), 3, "Error for Len !");
    cr_assert_eq(strlen(the_test), 20, "Error for the_test !");
}

Test(free_arr, free_malloc)
{
    char **array = malloc(sizeof(char *));

    array[0] = NULL;
    free_arr(array);
}
 
Test(start_simulation, verify_it_is_stdin, .init = redirect_all_std)
{
    char *testChar = "A";
    fflush(stdin);
    puts(testChar);
}

Test(help_move, move_test)
{
    char **array = malloc( 20 * sizeof(char *));

    for (int i = 0; i < 18; i++)
        array[i] = strdup("ppaz");
    array[19] = strdup("100");
    int q = help_move(1, 100, "papa", array);
    int a = help_move(221, 100, "papa", array);
    int b = help_move(221, 2100, "papa", array);
    cr_assert_eq(q, 0);
    cr_assert_eq(a, 0);
    cr_assert_eq(b, 0);
    int c = help_move(222, 222, "papa", array);
    int d = help_move(222, 22, "papa", array);
    cr_assert_eq(c, 1);
    cr_assert_eq(d, 0);
    int e = help_move(222, 242, "papa", array);
    cr_assert_eq(e, 0);
}

Test(count, count_char)
{
    char c = 'p';
    char *str = "papa";
    int ret = count(str, c);
    cr_assert_eq(ret, 2, "Error test !");
}

Test(str_to_array, split)
{
    char *str = "papa;papa";
    char *sep = ";";
    char **ret = NULL;
    ret = str_to_array(str, sep);

    cr_assert_arr_eq(ret, "papa", 0);
}
