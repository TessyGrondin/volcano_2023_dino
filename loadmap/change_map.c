/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** change_map
*/

#include "include/testmap.h"

void set_player_position(enti_t *player, sfVector2f last_pos)
{
    sfVector2f new_pos = {last_pos.x, last_pos.y};
    int width = 16 * 30;
    int height = 16 * 20;
    if (last_pos.x <= 32)
        new_pos.x = width - 35;
    if (last_pos.x >= (width - 32))
        new_pos.x = 35;
    if (last_pos.y <= 32)
        new_pos.y = height - 35;
    if (last_pos.y >= (height - 32))
        new_pos.y = 35;
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
        if (all->is_end != 1) {
            sfMusic_stop(all->sounds.loose_mus);
            sfMusic_stop(all->sounds.win_mus);
        }
        main_music_manager(&all->sounds, all->sounds.game_mus);
        pos = sfSprite_getPosition(all->player.sp.sp);
        x = (pos.x / 16); y = (pos.y / 16);
        index = (int)((x + 1) + y * (int)all->map.width);
        index2 = (int)(x + (y + 1) * (int)all->map.width);
        redirect(all, index, pos);
        redirect(all, index2, pos);
    }
}
