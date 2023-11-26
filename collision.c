/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** collision
*/

#include "include/testmap.h"

sfVector2f inverse_move(sprite_t *ent)
{
    sfVector2f left = {-1, 0};
    sfVector2f right = {1, 0};
    sfVector2f up = {0, -1};
    sfVector2f down = {0, 1};
    if (ent->anim == LEFT)
        return right;
    if (ent->anim == RIGHT)
        return left;
    if (ent->anim == UP)
        return down;
    if (ent->anim == DOWN)
        return up;
    return (sfVector2f){0, 0};
}

void expulse(all_t *all, sprite_t *ent, sfFloatRect *self, sfFloatRect *square)
{
    sfVector2f vec = inverse_move(ent);
    if (! all->charged) return;
    while (sfFloatRect_intersects(self, square, NULL) &&
    (vec.x != 0 || vec.y != 0)) {
        self->left += vec.x;
        self->top += vec.y;
        sfSprite_move(ent->sp, vec);
    }
}

void collisions(sprite_t *ent, all_t *all)
{
    sfFloatRect self = {0};
    sfFloatRect sq = {0};
    if (! all->charged) return;
    self = sfSprite_getGlobalBounds(ent->sp);
    // self.height = 29;
    // self.width = 20;
    // self.left += 8;
    // self.top += 4;
    for (unsigned int i = 0; i < (all->map.width * all->map.height); i++) {
        sq = sfRectangleShape_getGlobalBounds(all->map.collisions[i].rect);
        if (sfFloatRect_intersects(&self, &sq, NULL) &&
        all->map.collisions[i].state)
            expulse(all, ent, &self, &sq);
    }
}
