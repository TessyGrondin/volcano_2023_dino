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

int main(void)
{
    all_t all = init_all();
    all.map = initmap();
    srand(time(NULL));
    sfRenderWindow_setFramerateLimit(all.win, 60);
    sfSprite_setPosition(all.player.sp.sp, (sfVector2f){240, 128});
    while (sfRenderWindow_isOpen(all.win)) {
        handle_event(&all);
        display_menu(&all);
        game_loop(&all);
    }
    destroy_all(&all);
    return 0;
}
