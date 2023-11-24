/*
** EPITECH PROJECT, 2023
** navy
** File description:
** free
*/

#include <stdlib.h>
#include "../../include/my.h"

void freer(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void can_free(char *str)
{
    if (str)
        free(str);
}
