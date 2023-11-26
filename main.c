/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** norme_load_try
*/

#include "include/testmap.h"

void handle_event(all_t *all)
{
    while (sfRenderWindow_pollEvent(all->win, &all->event)) {
        if (all->event.type == sfEvtClosed)
            sfRenderWindow_close(all->win);
    }
}

void choose_state(all_t *all)
{
    sfRenderWindow_clear(all->win, sfBlack);
    if (all->states == MENU)
        display_menu(all);
    else if (all->states == INTRO)
        intro(all);
    else if (all->states == GAME)
        game_loop(all);
    else if (all->states == WIN)
        win(all);
    else if (all->states == LOOSE)
        loose(all);
    sfRenderWindow_display(all->win);
}

int main(void)
{
    all_t all = init_all();
    all.map = initmap();
    srand(time(NULL));
    sfRenderWindow_setFramerateLimit(all.win, 60);
    sfSprite_setPosition(all.player.sp.sp, (sfVector2f){700, 850});
    while (sfRenderWindow_isOpen(all.win)) {
        handle_event(&all);
        choose_state(&all);
    }
    destroy_all(&all);
    return 0;
}
