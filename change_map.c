/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** change_map
*/

#include "include/testmap.h"

void set_player_position(player_t *player, sfVector2f last_pos)
{
    sfVector2f new_pos = {last_pos.x, last_pos.y};
    int width = 32 * 50;
    int height = 32 * 40;
    if (last_pos.x <= 64)
        new_pos.x = width - 64;
    if (last_pos.x >= (width - 64))
        new_pos.x = 64;
    if (last_pos.y <= 64)
        new_pos.y = height - 64;
    if (last_pos.y >= (height - 64))
        new_pos.y = 64;
    sfSprite_setPosition(player->sp.sp, new_pos);
}

void change_map(all_t *all, int new_map)
{
    all->current_map = new_map;
    empty_level(all);
    all->charged = 0;
    reload(all);
    all->charged = 1;
}

void redirect(all_t *all, int index, sfVector2f pos)
{
    if (all->map.tiles[ENTRANCES][index] != -1) {
        set_player_position(&all->player, pos);
        change_map(all, all->map.tiles[ENTRANCES][index]);
    }
}

void read_entrances(all_t *all)
{
    sfVector2f pos = {0, 0};
    int x = 0;
    int y = 0;
    int index = 0;
    int index2 = 0;
    if (all->charged == 1) {
        main_music_manager(&all->sounds, all->sounds.game_mus);
        pos = sfSprite_getPosition(all->player.sp.sp);
        x = (pos.x / 32); y = (pos.y / 32);
        index = (int)((x + 1) + y * (int)all->map.width);
        index2 = (int)(x + (y + 1) * (int)all->map.width);
        redirect(all, index, pos);
        redirect(all, index2, pos);
    }
}
