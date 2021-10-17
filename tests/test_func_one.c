/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-clement.muth
** File description:
** test_func_one
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../string.h"

Test(my_string_is_good_simple, my_string_test)
{
    string_t s;

    string_init(&s, "Hello World");
    cr_assert_str_eq(s.str, "Hello World");
    s.string_destroy(&s);
}

Test(my_string_is_empty_easy, my_string_test)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_eq(s.length, 0);
}

Test(my_string_assign_easy, my_string_test)
{
    string_t s;

    string_init(&s, "Hello World");
    s.assign_c(&s, "what's up ?");
    cr_assert_str_eq(s.str, "what's up ?");
}

Test(my_string_assign_all_null, my_string_test)
{
    string_t s;
    string_t t;

    string_init(&s, "Hello World");
    s.assign_s(&s, NULL);
    cr_assert_str_eq(s.str, "Hello World");
}

Test(my_string_assign_null, my_string_test)
{
    string_t s;

    string_init(&s, "Hello World");
    s.assign_c(&s, NULL);
    cr_assert_str_eq(s.str, "Hello World");
}

Test(my_string_append_easy, my_string_test)
{
    string_t s;

    string_init(&s, "Hello World");
    s.append_c(&s, " what's up ?");
    cr_assert_str_eq(s.str, "Hello World what's up ?");
}

Test(my_string_append_null, my_string_test)
{
    string_t s;
    string_t t;

    string_init(&s, "Hello World");
    string_init(&t, NULL);
    s.append_s(&s, &t);
    cr_assert_str_eq(s.str, "Hello World");
}

Test(my_string_append_ap_null, my_string_test)
{
    string_t s;

    string_init(&s, "Hello World");
    s.append_s(&s, NULL);
    cr_assert_str_eq(s.str, "Hello World");
}

Test(my_string_at_easy, my_string_test)
{
    string_t s;
    char tmp;

    string_init(&s, "Hello World");
    tmp = s.at(&s, 2);
    cr_expect_eq(tmp, 'l');
}

Test(my_string_clear_easy, my_string_test)
{
    string_t s;

    string_init(&s, "Hello World");
    s.clear(&s);
    cr_expect_eq(s.str[0], '\0');
    cr_assert_eq(s.length, 0);
}

Test(my_string_copy_pierre, my_string_test)
{
    string_t s;
    char str[] = "init";

    string_init(&s, str);
    s.assign_c(&s, "pierre");
    cr_assert_eq(s.copy(&s, str, 3, 2), 3);
}

Test(my_string_copy_null_str, my_string_test)
{
    string_t s;
    char str[] = "init";

    string_init(&s, str);
    s.assign_c(&s, "\0");
    cr_assert_eq(s.copy(&s, str, 3, 2), 1);
}

Test(my_string_copy_null, my_string_test)
{
    string_t s;
    char str[] = "init";

    string_init(&s, str);
    cr_assert_eq(s.copy(&s, NULL, 3, 2), 0);
}

Test(my_string_c_str, my_string_test)
{
    string_t s;
    char str[] = "Hello World";

    string_init(&s, str);
    cr_assert_str_eq(s.c_str(&s), str);
}

Test(my_string_to_int, my_string_test)
{
    string_t s;
    char str[] = "12345";

    string_init(&s, str);
    cr_assert_eq(s.to_int(&s), 12345);
}

Test(my_size, my_string_test)
{
    string_t s;

    string_init(&s, "hello world");
    cr_assert_eq(s.size(&s), 11);
}

Test(my_size_with_null_value, my_string_test)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_eq(s.size(&s), -1);
}

Test(my_size_retest, my_string_test)
{
    string_t s;

    string_init(&s, "test");
    cr_assert_eq(s.size(&s), 4);
}

Test(my_compare_simple, my_string_test)
{
    string_t s;
    string_t t;

    string_init(&s, "test");
    string_init(&t, "test");
    cr_assert_eq(s.compare_s(&s, &t), 0);
}

Test(my_compare_with_bad_value, my_string_test)
{
    string_t s;
    string_t t;

    string_init(&s, "test");
    string_init(&t, "re");
    cr_assert_eq(s.compare_s(&s, &t), 2);
}

Test(my_str_empty_false, my_string_test)
{
    string_t s;

    string_init(&s, NULL);
    cr_assert_eq(s.empty(&s), 0);
}

Test(my_str_empty_true, my_string_test)
{
    string_t s;

    string_init(&s, "test");
    cr_assert_eq(s.empty(&s), 1);
}

Test(my_find_pos_zero, my_string_test)
{
    string_t s;
    string_t t;
    char str[] = "12345";

    string_init(&s, str);
    string_init(&t, str);
    cr_assert_eq(s.find_s(&s, &t, 0), 0);
}

Test(my_find_pos_greater_than_length, my_string_test)
{
    string_t s;
    string_t t;
    char str[] = "12345";

    string_init(&s, str);
    string_init(&t, "12345");
    cr_assert_eq(s.find_s(&s, &t, 100), -1);
}

Test(my_find_easy, my_string_test)
{
    string_t s;
    string_t t;
    char str[] = "12345";

    string_init(&s, str);
    string_init(&t, "5");
    cr_assert_eq(s.find_s(&s, &t, 2), 4);
}

Test(my_insert_simple, my_string_test)
{
    string_t s;
    char str[] = "12345";

    string_init(&s, str);
    s.insert_c(&s, 2, "0");
    cr_assert_str_eq(s.str, "123045");
}

Test(my_insert_pos_greater_than_length, my_string_test)
{
    string_t s;
    char str[] = "12345";

    string_init(&s, str);
    s.insert_c(&s, 10, "0");
    cr_assert_str_eq(s.str, "123450");
}

Test(my_insert_pos_lower_than_length, my_string_test)
{
    string_t s;
    char str[] = "12345";

    string_init(&s, str);
    s.insert_c(&s, -9, "0");
    cr_assert_str_eq(s.str, "12345");
}

Test(my_insert_pos_eq_length, my_string_test)
{
    string_t s;
    char str[] = "12345";

    string_init(&s, str);
    s.insert_c(&s, 5, "0");
    cr_assert_str_eq(s.str, "123450");
}

Test(my_insert_str_is_null, my_string_test)
{
    string_t s;
    char str[] = "12345";

    string_init(&s, str);
    s.insert_c(&s, 5, NULL);
    cr_assert_str_eq(s.str, "12345");
}