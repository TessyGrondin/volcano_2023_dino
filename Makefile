##
## EPITECH PROJECT, 2023
## loadmap
## File description:
## Makefile
##

SRC = 	getlvl.c\
		main.c\
		map_load.c\
		destroy.c\
		anim.c\
		move.c\
		player.c\
		read_layer.c\
		bite.c\
		collision.c\
		move2.c\
		bite_attack.c\
		change_map.c\
		map.c\
		map_collisions.c\
		reload.c\
		endgame.c\
		music.c\
		menu.c\
		button.c\
		loop.c

NAME = to_a_new_era

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
