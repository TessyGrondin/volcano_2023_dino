/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** str to tab
*/

#include "my.h"
#include <string.h>

char **tab_append(char **src, char *add)
{
    char **res = NULL;
    if (src == NULL) {
        res = malloc(sizeof(char*) * 2);
        res[0] = my_strdup(add);
        res[1] = NULL;
        return res;
    }
    res = malloc(sizeof(char *) * (my_tablen(CC(src)) + 2));
    for (int i = 0; i < my_tablen(CC(src)); i++)
        res[i] = my_strdup(src[i]);
    res[my_tablen(CC(src))] = my_strdup(add);
    res[my_tablen(CC(src)) + 1] = NULL;
    freer(src);
    return res;
}

char **my_str_to_word_array(char const *str, char const *delim)
{
    char **res = NULL;
    char *copy = my_strdup(str);
    char *part = strtok(copy, delim);
    while (part != NULL) {
        res = tab_append(res, part);
        part = strtok(NULL, delim);
    }
    free(copy);
    return res;
}
