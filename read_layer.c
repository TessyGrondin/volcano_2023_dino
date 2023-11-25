/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** read_layer
*/

#include "include/testmap.h"

target_t create_target(char *path, sfClock *clock)
{
    target_t res = {0};

    res.alive = sfTrue;
    res.sp = sp_create(path, clock);
    return (res);
}

void create_monster(all_t *all, sfVector2i pos)
{
    int i = 0;
    int j = 0;
    int color = 0;
    int index = pos.y * all->map.width + pos.x;
    sfVector2f set = {index % all->map.width * 16, index / all->map.width * 16};
    if (all->map.tiles[SPAWN][index] == -1)
        return;
    if (all->map.tiles[SPAWN][index] == 118) {
        for (; all->enemies[i].sp != NULL; i++);
        color = rand() % 2;
        if (color == 1)
            all->enemies[i] = sp_create(P_ENEMY1, all->clock);
        else
            all->enemies[i] = sp_create(P_ENEMY2, all->clock);
        all->enemies[i + 1].sp = NULL;
        sfSprite_setPosition(all->enemies[i].sp, set);
        return;
    }
    if (all->map.tiles[SPAWN][index] == 1) {
        for (; all->target[j].sp.sp != NULL; j++);
        color = rand() % 2;
        if (color == 1)
            all->target[j] = create_target(P_TARGET1, all->clock);
        else
            all->target[j] = create_target(P_TARGET2, all->clock);
        all->target[j + 1].sp.sp = NULL;
        sfSprite_setPosition(all->target[j].sp.sp, set);
        return;
    }
}

void spone_monster(all_t *all)
{
    for (unsigned int i = 0; i < all->map.width; i++) {
        for (unsigned int j = 0; j < all->map.height; j++)
            create_monster(all, (sfVector2i){i, j});
    }
}

void map_borders(all_t *all)
{
    int down = 20 * 16 - 32;
    int right = 30 * 16 - 32;
    sfVector2f pos;
    for (int i = 0; all->enemies[i].sp != NULL; i++) {
        pos = sfSprite_getPosition(all->enemies[i].sp);
        pos.x = (pos.x < 0) ? 0 : pos.x;
        pos.x = (pos.x > right) ? right : pos.x;
        pos.y = (pos.y < 0) ? 0 : pos.y;
        pos.y = (pos.y > down) ? down : pos.y;
        sfSprite_setPosition(all->enemies[i].sp, pos);
    }
    for (int i = 0; all->target[i].sp.sp != NULL; i++) {
        pos = sfSprite_getPosition(all->target[i].sp.sp);
        pos.x = (pos.x < 0) ? 0 : pos.x;
        pos.x = (pos.x > right) ? right : pos.x;
        pos.y = (pos.y < 0) ? 0 : pos.y;
        pos.y = (pos.y > down) ? down : pos.y;
        sfSprite_setPosition(all->target[i].sp.sp, pos);
    }
    pos = sfSprite_getPosition(all->player.sp.sp);
    pos.x = (pos.x < 0) ? 0 : pos.x;
    pos.x = (pos.x > right) ? right : pos.x;
    pos.y = (pos.y < 0) ? 0 : pos.y;
    pos.y = (pos.y > down) ? down : pos.y;
    sfSprite_setPosition(all->player.sp.sp, pos);
}
