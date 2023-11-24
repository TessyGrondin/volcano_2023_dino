##
## EPITECH PROJECT, 2023
## loadmap
## File description:
## Makefile
##

SRC = 	getlvl.c\
		norme_load_try.c\
		map_load.c\
		destroy.c\
		anim.c\
		move.c\
		player.c\
		read_layer.c\
		sword.c\
		life_barre.c\
		fire.c\
		fire2.c\
		collision.c\
		move2.c\
		sword2.c\
		npc.c\
		npc2.c\
		wheel.c\
		change_map.c\
		map.c\
		collisions_left.c\
		map_collisions.c\
		reload.c\
		state_rings.c\
		endgame.c\
		hp_modif.c\
		music.c\
		menu.c\
		button.c\
		loop.c

NAME = my_rpg

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -Werror -lcsfml-graphics -lcsfml-window -L \
	lib/my/ -lmy -I include/ -lcsfml-system \
	-lcsfml-audio -g -ggdb -g3 -lm

all: $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re: fclean all
