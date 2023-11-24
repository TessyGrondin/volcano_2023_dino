/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** sword2
*/

#include "include/testmap.h"

void sword_left(enti_t *player, enti_t *monster)
{
    float divide = 0;
    sfVector2f sword = sfSprite_getPosition(player->sp.sp);
    sfVector2f yeet = {0, 0};
    if (player->last_move == LEFT) {
        sword.x -= 10;
        yeet = sfSprite_getPosition(monster->sp.sp);
        yeet.x -= 5;
        sfSprite_setPosition(player->sword.sp, sword);
        if (is_colliding(&player->sword, &monster->sp) &&
        !monster->use_sword) {
            monster->use_sword = 1;
            sfSprite_setPosition(monster->sp.sp, yeet);
            divide = (5 / monster->def) < 1 ? 1 : (5 / monster->def);
            monster->hp -= (player->sword.value * player->attack / divide);
        } else
            monster->use_sword = 0;
    }
}

void sword_right(enti_t *player, enti_t *monster)
{
    float divide = 0;
    sfVector2f sword = sfSprite_getPosition(player->sp.sp);
    sfVector2f yeet = {0, 0};
    if (player->last_move == RIGHT) {
        sword.x += 10;
        yeet = sfSprite_getPosition(monster->sp.sp);
        yeet.x += 5;
        sfSprite_setPosition(player->sword.sp, sword);
        if (is_colliding(&player->sword, &monster->sp) &&
        !monster->use_sword) {
            monster->use_sword = 1;
            sfSprite_setPosition(monster->sp.sp, yeet);
            divide = (5 / monster->def) < 1 ? 1 : (5 / monster->def);
            monster->hp -= (player->sword.value * player->attack / divide);
        } else
            monster->use_sword = 0;
    }
}

void sword_up(enti_t *player, enti_t *monster)
{
    float divide = 0;
    sfVector2f sword = sfSprite_getPosition(player->sp.sp);
    sfVector2f yeet = {0, 0};
    if (player->last_move == UP) {
        sword.y -= 10;
        yeet = sfSprite_getPosition(monster->sp.sp);
        yeet.y -= 5;
        sfSprite_setPosition(player->sword.sp, sword);
        if (is_colliding(&player->sword, &monster->sp) &&
        !monster->use_sword) {
            monster->use_sword = 1;
            sfSprite_setPosition(monster->sp.sp, yeet);
            divide = (5 / monster->def) < 1 ? 1 : (5 / monster->def);
            monster->hp -= (player->sword.value * player->attack / divide);
        } else
            monster->use_sword = 0;
    }
}

void sword_down(enti_t *player, enti_t *monster)
{
    float divide = 0;
    sfVector2f sword = sfSprite_getPosition(player->sp.sp);
    sfVector2f yeet = {0, 0};
    if (player->last_move == DOWN) {
        sword.y += 10;
        yeet = sfSprite_getPosition(monster->sp.sp);
        yeet.y += 5;
        sfSprite_setPosition(player->sword.sp, sword);
        if (is_colliding(&player->sword, &monster->sp) &&
        !monster->use_sword) {
            monster->use_sword = 1;
            sfSprite_setPosition(monster->sp.sp, yeet);
            divide = (5 / monster->def) < 1 ? 1 : (5 / monster->def);
            monster->hp -= (player->sword.value * player->attack / divide);
        } else
            monster->use_sword = 0;
    }
}
