/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** sword
*/

#include "include/testmap.h"

int is_colliding(sprite_t *self, sprite_t *other)
{
    sfFloatRect hself = sfSprite_getGlobalBounds(self->sp);
    sfFloatRect hother = sfSprite_getGlobalBounds(other->sp);
    hself.height = hself.height / 2;
    hself.width = hself.width / 2;
    hself.left -= 5;
    hself.top += 5;
    hother.height = hother.height / 2;
    hother.width = hother.width / 2;
    hother.left -= 5;
    hother.top += 5;
    if (sfFloatRect_intersects(&hself, &hother, NULL)) {
        return 1;
    }
    return 0;
}

void check_sword_hit(enti_t *plr, enti_t *monsters)
{
    for (int i = 0; monsters[i].sp.sp != NULL; i++) {
        sword_left(plr, &monsters[i]);
        sword_right(plr, &monsters[i]);
        sword_up(plr, &monsters[i]);
        sword_down(plr, &monsters[i]);
    }
}

void use_sword(enti_t *player, all_t *all)
{
    sfVector2f sword = sfSprite_getPosition(player->sp.sp);
    sword.x -= 10;
    if (player->use_sword) {
        sfSprite_setPosition(player->sword.sp, sword);
        check_sword_hit(player, all->ent);
        player->use_sword = 0;
    }
}

void is_alive(all_t *all)
{
    for (int i = 0; all->ent[i].sp.sp; i++) {
        if (all->ent[i].hp <= 0 && all->ent[i].alive == 1) {
            all->ent[i].alive = 0;
            sfSound_play(all->sounds.hit);
        }
        if (all->ent[i].alive == 0) {
            give_hp(&all->player);
            all->player.exp += 10;
            all->ent[i].alive = 2;
        }
    }
}
