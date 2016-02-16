##
## Makefile for  in /home/coudra_c/rendu/PSU_2014_zappy
## 
## Made by Coudray Colin
## Login   <coudra_c@epitech.net>
## 
## Started on  Mon May 11 08:53:16 2015 Coudray Colin
## Last update Fri Jul  3 18:46:17 2015 Coudray Colin
##

CC		=	gcc

CFLAGS		+=	-W -Wall -Wextra -Werror -I./../includes

SRC_SERVER	=	main.c				\
			my_parse_arg.c			\
			my_parse_pxyct.c		\
			misc.c				\
			misc2.c				\
			manage_team.c			\
			manage_player.c			\
			my_init_serv.c			\
			my_init_map.c			\
			accept_new_client.c		\
			remove_player_from_events.c	\
			do_action.c			\
			init_fdsets.c			\
			network_part.c			\
			action_part.c			\
			player_network.c		\
			buff.c				\
			clean_server.c			\
			event.c				\
			case_player.c			\
			player_death.c			\
			free_player.c			\
			get_next_case.c			\
			objet_handling.c		\
			get_direction.c			\
			graphic_cmd.c			\
			graphic_instr.c			\
			manage_egg.c			\
			lvlup_aux.c			\
			instr_map.c			\
			instr_team.c			\
			instr_player_info.c		\
			instr_player_action.c		\
			instr_player_object.c		\
			instr_egg.c			\
			instr_server.c			\
			commandes/my_avance.c		\
			commandes/my_droite.c		\
			commandes/my_gauche.c		\
			commandes/my_voir.c		\
			commandes/my_inventaire.c	\
			commandes/my_prend_objet.c	\
			commandes/my_pose_objet.c	\
			commandes/my_expulse.c		\
			commandes/my_broadcast_texte.c	\
			commandes/my_incantation.c	\
			commandes/my_fork.c		\
			commandes/my_connect_nbr.c	\
			commandes/my_coord.c		\
			commandes/my_godmode.c		\
			commandes/my_msz.c		\
			commandes/my_bct.c		\
			commandes/my_mct.c		\
			commandes/my_tna.c		\
			commandes/my_ppo.c		\
			commandes/my_plv.c		\
			commandes/my_pin.c		\
			commandes/my_sgt.c		\
			commandes/my_sst.c		\
			events/pop_food.c		\
			events/kill_player.c		\
			events/lvlup.c			\
			events/end_fork.c		\
			events/egg_hatching.c		\
			events/finish_game.c

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

NAME_SERVER	=	../zappy_server

all: $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) -o $(NAME_SERVER) $(OBJ_SERVER)

clean:
	rm -f $(OBJ_SERVER)

fclean: clean
	rm -f $(NAME_SERVER)

re: fclean all
