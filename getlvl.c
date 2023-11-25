/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** getlvl
*/

#include "include/testmap.h"

all_t init_all(void)
{
    all_t res;
    make_base_material(&res);
    res.clock = sfClock_create();
    res.enemies = malloc(sizeof(sprite_t) * 31);
    res.target = malloc(sizeof(target_t) * 2);
    res.enemies[0].sp = NULL;
    res.target[0].sp.sp = NULL;
    res.move = sfTime_asSeconds(sfClock_getElapsedTime(res.clock));
    res.force_anim_change = 0;
    res.charged = 0;
    res.player = create_player(res.clock);
    res.end = sp_create(P_END, res.clock);

    // res.altar = create_altar(P_TARGET3, res.clock);
    res.altar = create_altar(P_TARGET3, res.clock);
    res.text = sfText_create();
    sfText_setFont(res.text, sfFont_createFromFile(P_FONT));
    sfText_setString(res.text, "hello");

    res.current_map = 4;
    res.is_end = 0;
    res.menu = get_menu(res.clock);
    res.e_menu = 0;
    res.sounds = get_all_sounds();
    return res;
}

map_t initmap(void)
{
    map_t res;
    res.height = 20;
    res.width = 30;
    res.vert = malloc(sizeof(sfVertexArray *) * 6);
    res.collisions = malloc(sizeof(collision_t) * 601);
    create_collisions(res.collisions);
    return res;
}

int *char_to_int(char **src)
{
    int *res = NULL;
    if (src == NULL)
        return NULL;
    res = malloc(sizeof(int) * (my_tablen((const char **)src) + 1));
    for (int i = 0; src[i]; i++)
        res[i] = my_getnbr(src[i]);
    res[my_tablen((const char **)src)] = -2;
    return res;
}

int *getlvl(const char *pathname)
{
    int op = open(pathname, O_RDONLY);
    struct stat buf;
    char *data = NULL;
    char **splits = NULL;
    int st = stat(pathname, &buf);
    int size = 0;
    int *res = NULL;
    if (st == -1 || op == -1)
        return NULL;
    data = malloc(sizeof(char) * (buf.st_size + 1));
    size = read(op, data, buf.st_size);
    if (size == -1)
        return NULL;
    data[buf.st_size] = '\0';
    splits = my_str_to_word_array(data, ",\n");
    free(data);
    res = char_to_int(splits);
    freer(splits);
    return res;
}

void get_all_layers(all_t *all)
{
    if (all->charged == 0) {
        all->map.nb_layer = my_tablen(maps[all->current_map]);
        all->map.tiles = malloc(sizeof(int *) * (all->map.nb_layer + 1));
        for (int i = 0; maps[all->current_map][i]; i++)
            all->map.tiles[i] = getlvl(maps[all->current_map][i]);
        all->map.tiles[all->map.nb_layer] = NULL;
        if (!map_load(&all->map, P_TILESET, (sfVector2u){16, 16}))
            return;
        spone_monster(all);
        all->charged = 1;
    }
}
