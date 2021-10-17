/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-clement.muth
** File description:
** string_compare
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "string.h"

int compare_c(const string_t *this, const char *str)
{
    return strcmp(this->str, str);
}

int compare_s(const string_t *this, const string_t *str)
{
    return compare_c(this, str->str);
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    int i = 0;

    if (!this->str || !s)
        return (i);
    while (n--) {
        s[i++] = this->str[pos++];
        if (!this->str[i - 1])
            return (i);
    }
    return (i);
}

const char *c_str(const string_t *this)
{
    return ((const char *)this->str);
}

int empty(const string_t *this)
{
    return (!this->str ? (0) : (1));
}