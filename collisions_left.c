/*
** EPITECH PROJECT, 1024
** loadmap
** File description:
** collisions_left
*/

#include "include/testmap.h"

void collision_left(enti_t *ent, all_t *all)
{
    sfFloatRect rect;
    sfFloatRect npc_rect = sfSprite_getGlobalBounds(all->npc.self.sp);
    sfVector2f new = {1, 0};
    npc_rect.height = 29;
    npc_rect.width = 10;
    npc_rect.left -= 6;
    npc_rect.top -= 3;
    if (ent->anim != LEFT && ent->anim != UPLEFT && ent->anim != DOWNLEFT)
        return;
    rect = sfSprite_getGlobalBounds(ent->sp.sp);
    rect.left -= 2;
    rect.height = 2;
    if (sfFloatRect_intersects(&rect, &npc_rect, NULL))
        sfSprite_move(ent->sp.sp, new);
}

void collision_right(enti_t *ent, all_t *all)
{
    sfFloatRect rect;
    sfFloatRect npc_rect = sfSprite_getGlobalBounds(all->npc.self.sp);
    sfVector2f new = {-1, 0};
    npc_rect.height = 29;
    npc_rect.width = 10;
    npc_rect.left -= 6;
    npc_rect.top -= 3;
    if (ent->anim != RIGHT && ent->anim != UPRIGHT && ent->anim != DOWNRIGHT)
        return;
    rect = sfSprite_getGlobalBounds(ent->sp.sp);
    rect.left += 2;
    rect.height = 2;
    if (sfFloatRect_intersects(&rect, &npc_rect, NULL))
        sfSprite_move(ent->sp.sp, new);
}

void collision_up(enti_t *ent, all_t *all)
{
    sfFloatRect rect;
    sfFloatRect npc_rect = sfSprite_getGlobalBounds(all->npc.self.sp);
    sfVector2f new = {0, 1};
    npc_rect.height = 29;
    npc_rect.width = 10;
    npc_rect.left -= 6;
    npc_rect.top -= 3;
    if (ent->anim != UP && ent->anim != UPLEFT && ent->anim != UPRIGHT)
        return;
    rect = sfSprite_getGlobalBounds(ent->sp.sp);
    rect.top -= 2;
    rect.width = 2;
    if (sfFloatRect_intersects(&rect, &npc_rect, NULL))
        sfSprite_move(ent->sp.sp, new);
}

void collision_down(enti_t *ent, all_t *all)
{
    sfFloatRect rect;
    sfFloatRect npc_rect = sfSprite_getGlobalBounds(all->npc.self.sp);
    sfVector2f new = {0, -1};
    npc_rect.height = 29;
    npc_rect.width = 10;
    npc_rect.left -= 6;
    npc_rect.top -= 3;
    if (ent->anim != DOWN && ent->anim != DOWNRIGHT && ent->anim != DOWNLEFT)
        return;
    rect = sfSprite_getGlobalBounds(ent->sp.sp);
    rect.left += 2;
    rect.width = 2;
    if (sfFloatRect_intersects(&rect, &npc_rect, NULL))
        sfSprite_move(ent->sp.sp, new);
}
