/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-clement.muth
** File description:
** string_cast
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "string.h"

int to_int(const string_t *this)
{
    return atoi(this->str);
}