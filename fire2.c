/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** fire2
*/

#include "include/testmap.h"

void check_hp(enti_t *ent, enti_t *plr)
{
    float divide = (5 / ent->def) < 1 ? 1 : (5 / ent->def);
    int hit = 0;
    if (ent->use_fire == 0 && plr->use_fire == 1) {
        hit = (int)(plr->ball.value * plr->attack / divide);
        hit = (plr->rings % 2) ? hit * 1.5 : hit;
        ent->hp -= hit;
        ent->use_fire = 1;
        return;
    }
    if (ent->use_wheel == 0 && plr->use_wheel == 1) {
        hit = (int)(plr->wheel.value * plr->attack / divide);
        hit = (plr->rings % 2) ? hit * 1.5 : hit;
        ent->hp -= hit;
        ent->use_wheel = 1;
    }
}

int fire_hit(all_t *all)
{
    if (all->player.use_fire == 0)
        return 0;
    for (int i = 0; all->ent[i].sp.sp; i++) {
        if (is_colliding(&all->player.ball, &all->ent[i].sp)) {
            check_hp(&all->ent[i], &all->player);
            all->ent[i].anim = 1;
            return 1;
        }
        if (is_colliding(&all->player.ball, &all->ent[i].sp) == 0)
            all->ent[i].use_fire = 0;
    }
    return 0;
}

int out_of_border(enti_t *player)
{
    sfVector2f pos = sfSprite_getPosition(player->ball.sp);
    pos.x += 16;
    pos.y += 16;
    if (pos.x < 0 || pos.x > (30 * 16)) {
        player->use_fire = 0;
        return 1;
    }
    if (pos.y < 0 || pos.y > (20 * 16)) {
        player->use_fire = 0;
        return 1;
    }
    return 0;
}

void fire_move(enti_t *player)
{
    sfVector2f movement = {0, 0};
    sfVector2f reset = sfSprite_getPosition(player->sp.sp);
    int ori = sfSprite_getRotation(player->ball.sp);
    if (player->use_fire) {
        if (ori == 270)
            movement.y = -1.5;
        if (ori == 180)
            movement.x = -1.5;
        if (ori == 90)
            movement.y = 1.5;
        if (ori == 0)
            movement.x = 1.5;
        sfSprite_move(player->ball.sp, movement);
    }
    if (player->use_fire == 0 || out_of_border(player))
        sfSprite_setPosition(player->ball.sp, reset);
}
