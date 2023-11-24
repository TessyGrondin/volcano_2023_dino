/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** read_layer
*/

#include "include/testmap.h"

void create_monster(all_t *all, sfVector2i pos)
{
    int i = 0;
    int color = 0;
    int index = pos.y * all->map.width + pos.x;
    sfVector2f set = {index % all->map.width * 16, index / all->map.width * 16};
    if (all->map.tiles[SPONE][index] == -1)
        return;
    if (all->map.tiles[SPONE][index] == 118) {
        for (; all->ent[i].sp.sp != NULL; i++);
        color = rand() % 2;
        if (color == 1)
            all->ent[i] = entit_create(all->clock, P_ENEMY1, "monster");
        else
            all->ent[i] = entit_create(all->clock, P_ENEMY2, "monster");
        all->ent[i + 1].sp.sp = NULL;
        sfSprite_setPosition(all->ent[i].sp.sp, set);
        return;
    }
    npc_range(all, index);
}

void spone_monster(all_t *all)
{
    all->npc.self.sp = NULL;
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
    for (int i = 0; all->ent[i].sp.sp != NULL; i++) {
        pos = sfSprite_getPosition(all->ent[i].sp.sp);
        pos.x = (pos.x < 0) ? 0 : pos.x;
        pos.x = (pos.x > right) ? right : pos.x;
        pos.y = (pos.y < 0) ? 0 : pos.y;
        pos.y = (pos.y > down) ? down : pos.y;
        sfSprite_setPosition(all->ent[i].sp.sp, pos);
    }
    pos = sfSprite_getPosition(all->player.sp.sp);
    pos.x = (pos.x < 0) ? 0 : pos.x;
    pos.x = (pos.x > right) ? right : pos.x;
    pos.y = (pos.y < 0) ? 0 : pos.y;
    pos.y = (pos.y > down) ? down : pos.y;
    sfSprite_setPosition(all->player.sp.sp, pos);
}
