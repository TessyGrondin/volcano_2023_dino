/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** state_rings
*/

#include "include/testmap.h"

void init_state(enti_t *res)
{
    res->anim = 0;
    res->attack = 20;
    res->def = 1;
    res->exp = 0;
    res->last = 0;
    res->hp = 100;
    res->alive = 1;
    res->invincible = 0;
    res->use_fire = 0;
    res->use_wheel = 0;
    res->use_sword = 0;
    res->rings = 0;
    res->max_hp = 100;
    res->level = 1;
}

sfBool is_def(int ring)
{
    if (ring == 2 || ring == 3)
        return sfTrue;
    if (ring == 6 || ring == 7)
        return sfTrue;
    return sfFalse;
}

void add_ring(all_t *all)
{
    if (all->current_map == 0 && all->player.rings % 2 == 0) {
        all->player.rings += 1;
        return;
    }
    if (all->current_map == 6 && all->player.rings < 4) {
        all->player.rings += 4;
        return;
    }
    if (all->current_map == 2 && !is_def(all->player.rings))
        all->player.rings += 2;
}

sfBool chest_open(all_t *all)
{
    if (all->current_map == 0 && all->player.rings % 2 == 1)
        return sfTrue;
    if (all->current_map == 6 && all->player.rings >= 4)
        return sfTrue;
    if (all->current_map == 2 && is_def(all->player.rings))
        return sfTrue;
    return sfFalse;
}

void set_chest(all_t *all)
{
    if (chest_open(all)) {
        all->npc.can_dialogue = -1;
        all->npc.self.frame = 4;
        sfSprite_setTextureRect(all->npc.self.sp, (sfIntRect){256, 0, 64, 64});
    }
}
