/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** sword
*/

#include "include/testmap.h"

sfBool collide_bite(sfFloatRect rect, sprite_t *other)
{
    sfFloatRect hother = sfSprite_getGlobalBounds(other->sp);
    rect.height = rect.height / 2;
    rect.width = rect.width / 2;
    rect.left -= 5;
    rect.top += 5;
    hother.height = hother.height / 2;
    hother.width = hother.width / 2;
    hother.left -= 5;
    hother.top += 5;
    if (sfFloatRect_intersects(&rect, &hother, NULL))
        return sfTrue;
    return sfFalse;
}

sfBool is_colliding(sprite_t *self, sprite_t *other)
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
    if (sfFloatRect_intersects(&hself, &hother, NULL))
        return sfTrue;
    return sfFalse;
}

void check_hit(player_t *player, target_t *target, int map)
{
    for (int i = 0; target[i].sp.sp != NULL; i++) {
        if (target[i].alive && target[i].map == map) {
            bite_left(player, &target[i]);
            bite_right(player, &target[i]);
            bite_up(player, &target[i]);
            bite_down(player, &target[i]);
        }
    }
}

void use_bite(player_t *player, all_t *all)
{
    sfVector2f sword = sfSprite_getPosition(player->sp.sp);
    sword.x -= 10;
    if (player->bite) {
        check_hit(player, all->target, all->current_map);
        player->bite = 0;
    }
}
