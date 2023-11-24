/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** copies an str in another place
*/

#include <stdlib.h>
#include "my.h"

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    if (src == NULL)
        return NULL;
    char *copy = malloc(sizeof(char) * (my_strlen(src) + 1));
    return my_strcpy(copy, src);
}
