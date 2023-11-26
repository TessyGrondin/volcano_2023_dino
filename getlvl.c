/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** getlvl
*/

#include "include/testmap.h"

target_t create_target(char *path, sfClock *clock)
{
    target_t res = {0};

    res.alive = sfTrue;
    res.sp = sp_create(path, clock, SP_WIDTH, SP_WIDTH);
    sfSprite_setScale(res.sp.sp, (sfVector2f){0.5, 0.5});
    return (res);
}

void create_target_arr(target_t *arr, sfClock *cl)
{
    if (!arr)
        return;
    for (int i = 0; i < 20; i++) {
        arr[i] = create_target(P_TARGET1, cl);
        arr[i].map = map_locations[i];
    }
    arr[20].sp.sp = NULL;
}

all_t init_all(void)
{
    all_t res = {0};
    make_base_material(&res);
    res.clock = sfClock_create();
    res.enemies = malloc(sizeof(sprite_t) * 31);
    res.target = malloc(sizeof(target_t) * 21);
    create_target_arr(res.target, res.clock);
    res.enemies[0].sp = NULL;
    res.move = sfTime_asSeconds(sfClock_getElapsedTime(res.clock));
    res.player = create_player(res.clock);
    res.end = sp_create(P_END, res.clock, 1920, 1080);
    res.altar = create_altar(P_AUTEL, res.clock);
    res.cine1 = sp_create(P_CINE1, res.clock, 342, 192);
    sfSprite_setScale(res.cine1.sp, (sfVector2f){1.41, 1.65});
    res.cine2 = sp_create(P_CINE2, res.clock, 342, 192);
    sfSprite_setScale(res.cine2.sp, (sfVector2f){1.41, 1.65});
    res.current_map = 4;
    res.menu = get_menu(res.clock);
    res.sounds = get_all_sounds();

    res.text1 = sfText_create();
    sfText_setFont(res.text1, sfFont_createFromFile(P_FONT));
    sfText_setString(res.text1, "");
    sfText_setScale(res.text1, (sfVector2f){0.5, 0.5});
    sfText_setPosition(res.text1, (sfVector2f){100, 140});

    res.text2 = sfText_create();
    sfText_setFont(res.text2, sfFont_createFromFile(P_FONT));
    sfText_setString(res.text2, "");
    sfText_setScale(res.text2, (sfVector2f){0.5, 0.5});
    sfText_setPosition(res.text2, (sfVector2f){100, 160});

    res.text3 = sfText_create();
    sfText_setFont(res.text3, sfFont_createFromFile(P_FONT));
    sfText_setString(res.text3, "");
    sfText_setScale(res.text3, (sfVector2f){0.5, 0.5});
    sfText_setPosition(res.text3, (sfVector2f){100, 180});

    res.text3 = sfText_create();
    sfText_setFont(res.text3, sfFont_createFromFile(P_FONT));
    sfText_setString(res.text3, "");
    sfText_setScale(res.text3, (sfVector2f){0.5, 0.5});
    sfText_setPosition(res.text3, (sfVector2f){100, 200});

    res.text4 = sfText_create();
    sfText_setFont(res.text4, sfFont_createFromFile(P_FONT));
    sfText_setString(res.text4, "");
    sfText_setScale(res.text4, (sfVector2f){0.5, 0.5});
    sfText_setPosition(res.text4, (sfVector2f){100, 200});

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
