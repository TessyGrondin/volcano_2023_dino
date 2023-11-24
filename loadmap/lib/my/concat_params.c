/*
** EPITECH PROJECT, 2022
** concat_params
** File description:
** return av as a string
*/

#include "../../include/my.h"
#include <stdlib.h>

char *concat_params(int size, char **src)
{
    int i = 0;
    int j = 0;
    char *res;

    while (i <= size) {
        j = j + my_strlen(src[i]);
        i = i + 1;
    }
    j = j + size + 1;
    res = malloc(sizeof(char) * j);
    for (int k = 0; src[k]; k++)
        my_strcat(res, src[k]);
    return res;
}
