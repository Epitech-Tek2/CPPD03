/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD03-clement.muth
** File description:
** print
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "string.h"

void print(const string_t *this)
{
    printf("%s", this->str);
}