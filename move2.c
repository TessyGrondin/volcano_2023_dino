/*
** EPITECH PROJECT, 2023
** SumiAngy
** File description:
** move2
*/

#include "include/testmap.h"

int is_move(int anim, int self)
{
    if (anim == ATT_B || anim == ATT_F || anim == ATT_S || anim == IDDLE)
        return self;
    return anim;
}

void hit_right(player_t *player)
{
    sfSprite_setScale(player->sp.sp, (sfVector2f){1, 1});
    sfSprite_setOrigin(player->sp.sp, (sfVector2f){0, 0});
    if (player->last_move == RIGHT) {
        sfSprite_setScale(player->sp.sp, (sfVector2f){-1, 1});
        sfSprite_setOrigin(player->sp.sp, (sfVector2f){40, 0});
        player->sp.anim = ATT_S;
    }
}

void find_last_move(player_t *player)
{
    if (player->last_move == LEFT) {
        player->sp.anim = ATT_S;
        return;
    }
    if (player->last_move == UP || player->last_move == UPRIGHT ||
    player->last_move == UPLEFT) {
        player->sp.anim = ATT_F;
        return;
    }
    if (player->last_move == DOWN || player->last_move == DOWNRIGHT ||
    player->last_move == DOWNLEFT) {
        player->sp.anim = ATT_B;
        return;
    }
    hit_right(player);
}
