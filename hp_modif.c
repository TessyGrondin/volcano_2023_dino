/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** hp_modif
*/

#include "include/testmap.h"

void is_hp_ring(enti_t *player)
{
    if (player->rings >= 4)
        player->max_hp = 160;
}

void give_hp(enti_t *player)
{
    int plus = rand() % 3;
    if (plus == 1)
        player->hp += 10;
    if (player->hp > player->max_hp)
        player->hp = player->max_hp;
}
