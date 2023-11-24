/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** i = "dest" +"src"
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    if (dest == NULL)
        return my_strdup(src);
    for (int i = 0; src[i]; i++) {
        dest = my_append(dest, src[i]);
    }
    return dest;
}
