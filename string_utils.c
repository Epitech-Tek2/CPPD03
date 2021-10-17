/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-clement.muth
** File description:
** string_utils
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "string.h"

void next_init(string_t *this)
{
    this->string_destroy = string_destroy;
    this->size = size;
    this->to_int = to_int;
    this->print = print;
}

void string_init(string_t *this, const char *s)
{
    this->append_c = append_c;
    this->append_s = append_s;
    this->assign_c = assign_c;
    this->assign_s = assign_s;
    this->at = at;
    this->length = (s) ? strlen(s) : (size_t)0;
    this->buffer = (s) ? MAX(this->length, ((size_t)10)) : (size_t)0;
    this->c_str = c_str;
    this->clear = clear;
    this->compare_c = compare_c;
    this->compare_s = compare_s;
    this->copy = copy;
    this->empty = empty;
    this->find_c = find_c;
    this->find_s = find_s;
    this->insert_c = insert_c;
    this->insert_s = insert_s;
    this->str = (s) ? strdup(s) : NULL;
    next_init(this);
}

void clear(string_t *this)
{
    if (this->str)
        this->str[0] = '\0';
    this->length = 0;
}

void string_destroy(string_t *this)
{
    if (this->str)
        free(this->str);
    memset(this, 0, sizeof(string_t));
}

int size(const string_t *this)
{
    if (!this || !this->str)
        return (-1);
    return ((int)strlen(this->str));
}