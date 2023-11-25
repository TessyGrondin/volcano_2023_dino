/*
** EPITECH PROJECT, 2022
** button handling
** File description:
** button related functions
*/

#include "include/testmap.h"

sfBool wait_one(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    sfIntRect r = {128, 0, 64, 24};
    if (timing - all->move <= 2) {
        all->menu.start.state = 2;
        sfSprite_setTextureRect(all->menu.start.look.sp, r);
        sfRenderWindow_drawSprite(all->win, all->menu.start.look.sp, NULL);
        return sfTrue;
    }
    sfSound_play(all->sounds.button_sound);
    return sfFalse;
}

void button_state(button_t *button)
{
    sfIntRect color = sfSprite_getTextureRect(button->look.sp);
    if (button->state == 0)
        color.left = 0;
    if (button->state == 1)
        color.left = color.width;
    if (button->state == 2)
        color.left = color.width * 2;
    sfSprite_setTextureRect(button->look.sp, color);
}

int button_click(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->win);
    sfFloatRect hitbox = {1400, 320, 192, 72};
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfFloatRect_contains(&hitbox, mouse.x, mouse.y))
        all->menu.start.state = 2;
    if (all->menu.start.state == 2) {
        if (!wait_one(all))
            return 1;
    }
    return 0;
}

void button_highlight(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->win);
    sfFloatRect hitbox = {1400, 320, 256, 72};
    if (button_click(all)) {
        all->menu.start.state = 2;
        button_state(&all->menu.start);
        return;
    }
    if (all->menu.start.state != 2) {
        if (sfFloatRect_contains(&hitbox, mouse.x, mouse.y) &&
            sfMouse_isButtonPressed(sfMouseLeft) == sfFalse) {
            all->menu.start.state = 1;
        } else
            all->menu.start.state = 0;
    }
    button_state(&all->menu.start);
}

void display_button(button_t *button, all_t *all, sfVector2f pos)
{
    if (button->look.sp!= NULL && button->look.tex != NULL) {
        sfSprite_setPosition(button->look.sp, pos);
        sfRenderWindow_drawSprite(all->win, button->look.sp, NULL);
    }
}
