/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** pnj
*/

#include "include/testmap.h"

// npc_t npc_create(char *name, all_t *all)
// {
//     npc_t res;
//     char *dialogue = (char *)dialogue_path[all->current_map];
//     res.self = sp_create(name, all->clock);
//     res.can_dialogue = 0;
//     res.dialogue = sp_create(dialogue, all->clock);
//     if (my_strcmp(name, P_DRAGON) == 0) {
//         sfSprite_setTextureRect(res.self.sp, (sfIntRect){0, 0, 256, 256});
//     }
//     if (my_strcmp(name, P_CHEST) == 0)
//         sfSprite_setTextureRect(res.self.sp, (sfIntRect){0, 0, 64, 64});
//     sfSprite_setTextureRect(res.dialogue.sp, (sfIntRect){0, 0, 512, 256});
//     return res;
// }

// void interaction(npc_t *npc, all_t *all)
// {
//     // npc_collisions(all);
//     if (is_colliding(&all->player.sp, &npc->self) &&
//     sfKeyboard_isKeyPressed(sfKeyF)) {
//         if (npc->can_dialogue == 1) {
//             npc->can_dialogue = 0;
//         } else {
//             npc->can_dialogue = 1;
//         }
//     }
// }

void anim_npc(target_t *target, all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->clock);
    float timing = sfTime_asSeconds(time);
    sfIntRect rect = sfSprite_getTextureRect(target->sp.sp);
    if (timing - target->sp.lat >= 0.15) {
        if (target->sp.frame == 3) {
            target->sp.frame = 0;
            rect.left = 0;
        } else {
            rect.left += 32;
            target->sp.frame++;
        }
        sfSprite_setTextureRect(target->sp.sp, rect);
        target->sp.lat = timing;
    }
}

// void anim_dragon(npc_t *dragon, all_t *all)
// {
//     sfTime time = sfClock_getElapsedTime(all->clock);
//     float timing = sfTime_asSeconds(time);
//     sfIntRect rect = sfSprite_getTextureRect(dragon->self.sp);
//     if (timing - dragon->self.lat >= 0.10) {
//         if (dragon->self.frame == 16) {
//             rect.left = 0;
//             dragon->self.frame = 0;
//         } else {
//             rect.left += 256;
//             dragon->self.frame++;
//         }
//         sfSprite_setTextureRect(dragon->self.sp, rect);
//         dragon->self.lat = timing;
//     }
// }

// void anim_chest(npc_t *chest, all_t *all)
// {
//     sfIntRect rect = {0};
//     sfTime time = sfClock_getElapsedTime(all->clock);
//     float timing = sfTime_asSeconds(time);
//     if (chest->self.frame == 4 || !chest->can_dialogue)
//         return;
//     sfSprite_move(all->player.sp.sp, inverse_move(&all->player));
//     rect = sfSprite_getTextureRect(chest->self.sp);
//     if (timing - chest->self.lat >= 0.10) {
//         if (chest->self.frame == 4)
//             return;
//         else {
//             rect.left += 64;
//             chest->self.frame++;
//         }
//         sfSprite_setTextureRect(chest->self.sp, rect);
//         chest->self.lat = timing;
//     }
// }
