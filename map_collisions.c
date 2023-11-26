/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** map_collisions
*/

#include "include/testmap.h"

sfBool create_collisions(collision_t *array)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < (40 * 50); i++) {
        if (!(array[i].rect = sfRectangleShape_create()))
            return sfFalse;
        array[i].state = sfFalse;
        sfRectangleShape_setSize(array[i].rect, (sfVector2f){32, 32});
        sfRectangleShape_setPosition(array[i].rect, (sfVector2f){x, y});
        sfRectangleShape_setOutlineThickness(array[i].rect, 1);
        sfRectangleShape_setOutlineColor(array[i].rect, sfWhite);
        sfRectangleShape_setFillColor(array[i].rect, sfTransparent);
        x += 32;
        if (x >= (50 * 32)) {
            x = 0;
            y += 32;
        }
    }
    return sfTrue;
}

void fill_collision(map_t *map, int x, int y)
{
    int index = y * map->width + x;
    sfVector2f set = {index % map->width * 32, index / map->width * 32};
    if (map->tiles[COLLISION][index] == -1)
        return;
    map->collisions[index].state = sfTrue;
    sfRectangleShape_setPosition(map->collisions[index].rect, set);
    sfRectangleShape_setFillColor(map->collisions[index].rect, sfBlue);
}

void fill_all_collisions(map_t *map)
{
    for (unsigned int i = 0; i < map->width; i++)
        for (unsigned int j = 0; j < map->height; j++)
            fill_collision(map, i, j);
}

void monster_collisions(all_t *all)
{
    if (!all->charged)
        return;
    for (int i = 0; all->enemies[i].sp; i++) {
        collisions(&all->enemies[i], all);
    }
}
