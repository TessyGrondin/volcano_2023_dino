/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** npc2
*/

#include "include/testmap.h"

// void npc_range(all_t *all, int index)
// {
//     sfVector2f set = {index % all->map.width * 16, index / all->map.width * 16};
//     if (all->map.tiles[SPONE][index] == 1)
//         all->npc = npc_create(P_NPC2, all);
//     if (all->map.tiles[SPONE][index] == 2)
//         all->npc = npc_create(P_NPC1, all);
//     if (all->map.tiles[SPONE][index] == 3)
//         all->npc = npc_create(P_NPC3, all);
//     if (all->map.tiles[SPONE][index] == 4)
//         all->npc = npc_create(P_DRAGON, all);
//     if (all->map.tiles[SPONE][index] == 5)
//         all->npc = npc_create(P_CHEST, all);
//     if (all->map.tiles[SPONE][index] != -1)
//         sfSprite_setPosition(all->npc.self.sp, set);
// }

// void play_dialogue(npc_t *npc, all_t *all)
// {
//     sfVector2f pos = {100, 190};
//     sfSprite_setScale(npc->dialogue.sp, (sfVector2f){0.5, 0.5});
//     sfSprite_setPosition(npc->dialogue.sp, pos);
//     if (my_strcmp(npc->self.name, P_CHEST) == 0) {
//         if (npc->self.frame == 4)
//             npc->can_dialogue = -1;
//         sfSprite_setTextureRect(npc->dialogue.sp, (sfIntRect){0, 0, 409, 97});
//     }
//     if (npc->can_dialogue == 1) {
//         sfRenderWindow_drawSprite(all->win, npc->dialogue.sp, NULL);
//     }
// }

// void npc_collisions(all_t *all)
// {
//     if (my_strcmp(all->npc.self.name, P_CHEST) == 0)
//         return;
//     collision_down(&all->player, all);
//     collision_left(&all->player, all);
//     collision_right(&all->player, all);
//     collision_up(&all->player, all);
// }

// void redirection_animation(npc_t *npc, all_t *all)
// {
//     if (my_strcmp(npc->self.name, P_DRAGON) == 0) {
//         anim_dragon(npc, all);
//         return;
//     }
//     if (my_strcmp(npc->self.name, P_CHEST) == 0) {
//         anim_chest(npc, all);
//         if (npc->self.frame == 4 && npc->can_dialogue != -1)
//             add_ring(all);
//         set_chest(all);
//         return;
//     }
//     anim_npc(npc, all);
// }
