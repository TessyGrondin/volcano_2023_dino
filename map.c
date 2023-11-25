/*
** EPITECH PROJECT, 2023
** loadmap
** File description:
** map
*/

#include "layers_header.h"

char const * layers_0_0[] = {
"config/map_0_0/map00_ground.csv",
"config/map_0_0/map00_trees.csv",
"config/map_0_0/map00_road.csv",
"config/map_0_0/map00_entrance.csv",
"config/map_0_0/map00_collision.csv",
"config/map_0_0/map00_spawn.csv",
NULL,
};
char const * layers_0_1[] = {
"config/map_0_1/map01_ground.csv",
"config/map_0_1/map01_trees.csv",
"config/map_0_1/map01_road.csv",
"config/map_0_1/map01_entrance.csv",
"config/map_0_1/map01_collision.csv",
"config/map_0_1/map01_spawn.csv",
NULL,
};
char const * layers_0_2[] = {
"config/map_0_2/map02_ground.csv",
"config/map_0_2/map02_trees.csv",
"config/map_0_2/map02_road.csv",
"config/map_0_2/map02_entrance.csv",
"config/map_0_2/map02_collision.csv",
"config/map_0_2/map02_spawn.csv",
NULL,
};
char const * layers_1_0[] = {
"config/map_1_0/map10_ground.csv",
"config/map_1_0/map10_trees.csv",
"config/map_1_0/map10_road.csv",
"config/map_1_0/map10_entrance.csv",
"config/map_1_0/map10_collision.csv",
"config/map_1_0/map10_spawn.csv",
NULL,
};
char const * layers_1_1[] = {
"config/map_1_1/map11_ground.csv",
"config/map_1_1/map11_trees.csv",
"config/map_1_1/map11_road.csv",
"config/map_1_1/map11_entrance.csv",
"config/map_1_1/map11_collision.csv",
"config/map_1_1/map11_spawn.csv",
NULL,
};
char const * layers_1_2[] = {
"config/map_1_2/map12_ground.csv",
"config/map_1_2/map12_trees.csv",
"config/map_1_2/map12_road.csv",
"config/map_1_2/map12_entrance.csv",
"config/map_1_2/map12_collision.csv",
"config/map_1_2/map12_spawn.csv",
NULL,
};
char const * layers_2_0[] = {
"config/map_2_0/map20_ground.csv",
"config/map_2_0/map20_trees.csv",
"config/map_2_0/map20_road.csv",
"config/map_2_0/map20_entrance.csv",
"config/map_2_0/map20_collision.csv",
"config/map_2_0/map20_spawn.csv",
NULL,
};
char const * layers_2_1[] = {
"config/map_2_1/map21_ground.csv",
"config/map_2_1/map21_trees.csv",
"config/map_2_1/map21_road.csv",
"config/map_2_1/map21_entrance.csv",
"config/map_2_1/map21_collision.csv",
"config/map_2_1/map21_spawn.csv",
NULL,
};
char const * layers_2_2[] = {
"config/map_2_2/map22_ground.csv",
"config/map_2_2/map22_trees.csv",
"config/map_2_2/map22_road.csv",
"config/map_2_2/map22_entrance.csv",
"config/map_2_2/map22_collision.csv",
"config/map_2_2/map22_spawn.csv",
NULL,
};

char const ** maps[] = {
layers_0_0,
layers_1_0,
layers_2_0,
layers_0_1,
layers_1_1,
layers_2_1,
layers_0_2,
layers_1_2,
layers_2_2,
NULL,
};

int const map_locations[] = {
0,
1,
1,
1,
2,
3,
4,
4,
5,
6,
8,
8,
9,
10,
10,
11,
13,
14,
14,
14
};
