/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-clement.muth
** File description:
** string_finder
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "string.h"

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *tmp;

    if (this->length <= pos)
        return (-1);
    tmp = strstr(&this->str[pos], str);
    return (tmp) ? (tmp - this->str) : (-1);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return this->find_c(this, str->str, pos);
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *before = malloc(pos + 1);
    char *after;
    string_t insert;

    if (!this || !this->str || !str || (int)pos < 0)
        return;
    after = malloc(strlen(str) - pos + 1);
    if (pos >= this->length)
		return this->append_c(this, str);
    for (int i = 0; i <= (int)pos; i++)
        before[i] = this->str[i];
    before[pos + 1] = '\0';
    for (int i = pos + 1, n = 0; this->str[i]; i++, n++)
        after[n] = this->str[i];
    after[(strlen(str) - pos)] = '\0';
    string_init(&insert, before);
    insert.append_c(&insert, str);
    insert.append_c(&insert, after);
    this->assign_s(this, &insert);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    insert_c(this, pos, str->str);
}