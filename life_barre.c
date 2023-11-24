/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** life_barre
*/

#include "include/testmap.h"

sfRectangleShape *hp_create(sfVector2f pos)
{
    sfRectangleShape *res = sfRectangleShape_create();
    sfRectangleShape_setSize(res, (sfVector2f){2, 15});
    sfRectangleShape_setFillColor(res, sfRed);
    sfRectangleShape_setPosition(res, pos);
    return res;
}

void draw_life_barre(all_t *all)
{
    for (int i = 0; i < all->player.hp; i++)
        sfRenderWindow_drawRectangleShape(all->win, all->life[i], NULL);
}

sfRectangleShape **create_life_barre(void)
{
    sfRectangleShape **barre = malloc(sizeof(sfRectangleShape *) * 161);
    sfVector2f pos = {0, 0};
    barre[160] = NULL;
    for (int i = 0; i < 160; i++) {
        barre[i] = hp_create(pos);
        pos.x += 2;
    }
    return barre;
}

void get_hit(all_t *all)
{
    float divide = 0;
    int hit = 0;
    for (int i = 0; all->ent[i].sp.sp; i++) {
        if (is_colliding(&all->player.sp, &all->ent[i].sp) &&
        (all->player.anim != 1 &&
        !is_colliding(&all->player.sword, &all->ent[i].sp)) &&
        all->player.invincible == 0 && all->ent[i].alive == 1) {
            divide = (5 / all->player.def) < 1 ? 1 : (5 / all->player.def);
            hit = (int)(all->ent[i].attack / divide);
            hit = is_def(all->player.rings) ? hit * 0.5 : hit;
            all->player.hp -= hit;
            all->player.invincible = 1;
        }
    }
}