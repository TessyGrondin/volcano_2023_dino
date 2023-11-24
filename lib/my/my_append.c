/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_append
*/

#include "my.h"

char *my_append(char *str, char c)
{
    int i = 0;
    char *res;
    if (str == NULL) {
        res = malloc(sizeof(char) * 2);
        res[0] = c;
        res[1] = '\0';
        return res;
    }
    res = malloc(sizeof(char) * (my_strlen(str) + 2));
    for (; str[i]; i++)
        res[i] = str[i];
    res[i] = c;
    res[i + 1] = '\0';
    free(str);
    return res;
}

char *my_unappend(char *str)
{
    char *res = NULL;
    for (int i = 1; str[i]; i++)
        res = my_append(res, str[i - 1]);
    free(str);
    return res;
}
