/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** find an str in another one
*/

#include <stddef.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = my_strlen(to_find);
    int j = 1;
    char *test = str + j;
    int res = 0;

    if (i > my_strlen(str))
        return NULL;
    res = my_strncmp(str, to_find, i - 1);
    if (res == 0)
        return str;
    while (res != 0 && test[0] != '\0') {
        res = my_strncmp(test, to_find, i - 1);
        if (res == 0)
            return test;
        test = str + j;
        j = j + 1;
    }
    return NULL;
}
