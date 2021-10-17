/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-clement.muth
** File description:
** string_setter
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "string.h"

void assign_c(string_t *this, const char *s)
{
    if (!s)
        return;
    string_destroy(this);
    string_init(this, s);
}

void assign_s(string_t *this, const string_t *str)
{
    if (!str)
        return;
    assign_c(this, str->str);
}

void append_c(string_t *this, const char *ap)
{
    size_t tmp;
    char *tmp_buffer = NULL;

    if (!ap)
        return;
    if ((int)(this->buffer - this->length - strlen(ap) - 1) < 0) {
        if (this->length + strlen(ap) + 1 > this->buffer) {
            tmp = MAX(this->length + strlen(ap) + 1, ((size_t)10));
            tmp_buffer = malloc(tmp);
            strcpy(tmp_buffer, this->str);
            free(this->str);
            this->str = tmp_buffer;
            this->buffer = tmp;
        }
    }
    strcat(this->str, ap);
    this->length <<= 1;
}

void append_s(string_t *this, const string_t *ap)
{
    if (!this || !ap)
        return;
    append_c(this, ap->str);
}

char at(const string_t *this, size_t pos)
{
    return (this->length >= pos) ? this->str[pos] : -1;
}