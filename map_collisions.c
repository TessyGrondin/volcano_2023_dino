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
    for (int i = 0; i < 600; i++) {
        if (!(array[i].rect = sfRectangleShape_create()))
            return sfFalse;
        array[i].state = sfFalse;
        sfRectangleShape_setSize(array[i].rect, (sfVector2f){16, 16});
        sfRectangleShape_setPosition(array[i].rect, (sfVector2f){x, y});
        sfRectangleShape_setOutlineThickness(array[i].rect, 1);
        sfRectangleShape_setOutlineColor(array[i].rect, sfWhite);
        sfRectangleShape_setFillColor(array[i].rect, sfTransparent);
        x += 16;
        if (x >= (30 * 16)) {
            x = 0;
            y += 16;
        }
    }
    return sfTrue;
}

void fill_collision(map_t *map, int x, int y, int layer)
{
    int index = y * map->width + x;
    sfVector2f set = {index % map->width * 16, index / map->width * 16};
    if (map->tiles[layer][index] == -1)
        return;
    if (layer == COLLISION) {
        map->collisions[index].state = sfTrue;
        sfRectangleShape_setPosition(map->collisions[index].rect, set);
        sfRectangleShape_setFillColor(map->collisions[index].rect, sfBlue);
    } else {
        map->road[index].state = sfTrue;
        sfRectangleShape_setPosition(map->road[index].rect, set);
        sfRectangleShape_setFillColor(map->road[index].rect, sfBlue);
    }
}

void fill_all_collisions(map_t *map)
{
    for (unsigned int i = 0; i < map->width; i++) {
        for (unsigned int j = 0; j < map->height; j++) {
            fill_collision(map, i, j, COLLISION);
            fill_collision(map, i, j, ROAD);
        }
    }
}

void monster_collisions(all_t *all)
{
    if (!all->charged)
        return;
    for (int i = 0; all->ent[i].sp.sp; i++) {
        collisions(&all->ent[i], all);
        road_collisions(&all->ent[i], all);
    }
}
