/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** bite2
*/

#include "include/testmap.h"

void bite_left(player_t *player, target_t *target)
{
    sfFloatRect bite = sfSprite_getGlobalBounds(player->sp.sp);
    bite.left -= 5;
    if (player->last_move == LEFT && collide_bite(bite, &target->sp)) {
        player->offering++;
        target->alive = sfFalse;
    }
}

void bite_right(player_t *player, target_t *target)
{
    sfFloatRect bite = sfSprite_getGlobalBounds(player->sp.sp);
    bite.left += 5;
    if (player->last_move == RIGHT && collide_bite(bite, &target->sp)) {
        player->offering++;
        target->alive = sfFalse;
    }
}

void bite_up(player_t *player, target_t *target)
{
    sfFloatRect bite = sfSprite_getGlobalBounds(player->sp.sp);
    bite.top -= 5;
    if (player->last_move == UP && collide_bite(bite, &target->sp)) {
        player->offering++;
        target->alive = sfFalse;
    }
}

void bite_down(player_t *player, target_t *target)
{
    sfFloatRect bite = sfSprite_getGlobalBounds(player->sp.sp);
    bite.top += 5;
    if (player->last_move == DOWN && collide_bite(bite, &target->sp)) {
        player->offering++;
        target->alive = sfFalse;
    }
}
