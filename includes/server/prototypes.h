/*
** prototypes.h for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon May 11 09:03:49 2015 Coudray Colin
** Last update Wed Jul  1 16:52:10 2015 Coudray Colin
*/

#ifndef SERVER_PROTOTYPES_H_
#define SERVER_PROTOTYPES_H_

#include <sys/select.h>

/*
** MISCELLANEOUS
*/
int	my_valid_number(char *);
char	*strnchr(char *, char, int);
void	add_time(struct timeval *, float);
float	sub_time(struct timeval *, struct timeval *);
int	my_timediff(struct timeval *, struct timeval *);
int	get_next_case(t_server *, t_player *);
void	adjust_coord(t_server *, int *, int *);
char	*get_second_word(char *);
int	is_object(char *);
int	get_direction(t_server *, t_player *, t_player *);
int	nb_same_lvl_player(t_server *, int, int);
int	enough_stone_to_lvlup(t_server *, t_player *);
void	consum_stones(t_server *, int, int);
void	broadcast_incantation_result(t_server *, long, int);
void	say_bye_to_players(t_server *);

/*
** PARSING
*/
int	my_parse_arg(t_server *, int, char **);
int	my_parse_p(t_server *, int, char **);
int	my_parse_x(t_server *, int, char **);
int	my_parse_y(t_server *, int, char **);
int	my_parse_c(t_server *, int, char **);
int	my_parse_t(t_server *, int, char **);
int	my_parse_n(t_server *, int, char **);
int	my_parse_v(t_server *, int, char **);

/*
** TEAM
*/
void	add_team(t_server *, char *);
int	nb_player_in_team(t_team *);
int	my_nb_team(t_team *);

/*
** PLAYER
*/
void	add_player(t_player **, t_player *);
int	add_player_to_team(t_server *, t_player *, char *);
int	add_player_to_case(t_server *, t_player *, int);
void	add_player_to_graphic(t_server *, t_player *);
void	free_player(t_player **, t_player *);
int	player_read(t_server *, t_player **, t_player **);
void	player_write(t_server *, t_player *);
void	remove_player_from_team(t_player **, t_player *);
void	remove_player_from_case(t_server *, t_player *, int);
void	remove_player_from_events(t_server *, t_player *);
int	move_player(t_server *, t_player *, int, int);
void	place_player(t_server *, t_player *);
void	player_death(t_server *, t_player *);

/*
** SERVER
*/
int	my_init_serv(t_server *);
void	accept_new_client(t_server *);
void	main_loop_network(t_server *, fd_set *, fd_set *, struct timeval *);
void	new_player_network(t_server *, fd_set *, fd_set *);
void	graphic_network(t_server *, fd_set *, fd_set *);
int	init_fdsets(t_server *, fd_set *, fd_set *, struct timeval *);
void	clean_server(t_server *);
int	my_init_map(t_server *);
void	new_player_handler(t_server *);
void	player_actions(t_server *);
void	graphic_handler(t_server *);
void	declare_eggs_to_graphic(t_server *, t_player *);

/*
** BUFF
*/
char	*get_instruction(t_player *);
void	buff_append(t_buff *, char *, int);
void	buff_remove(t_buff *, int);

/*
** EVENTS
*/
int	register_event(t_server *, e_event, float, void *);
void	handle_events(t_server *);
void	pop_food(t_server *, void *);
void	kill_player(t_server *, void *);
void	egg_hatching(t_server *, void *);
void	lvlup(t_server *, void *);
void	end_fork(t_server *, void *);
void	finish_game(t_server *, void *);

/*
** GAME RUNNING
*/
int	do_action(t_server *, t_player *, char *);
void	my_avance(t_server *, t_player *, char *);
void	my_droite(t_server *, t_player *, char *);
void	my_gauche(t_server *, t_player *, char *);
void	my_voir(t_server *, t_player *, char *);
void	my_inventaire(t_server *, t_player *, char *);
void	my_prend_objet(t_server *, t_player *, char *);
void	my_pose_objet(t_server *, t_player *, char *);
void	my_expulse(t_server *, t_player *, char *);
void	my_broadcast_texte(t_server *, t_player *, char *);
void	my_incantation(t_server *, t_player *, char *);
void	my_fork(t_server *, t_player *, char *);
void	my_connect_nbr(t_server *, t_player *, char *);
void	my_godmode(t_server *, t_player *, char *);
void	my_coord(t_server *, t_player *, char *);
void	graphic_cmd(t_server *, t_player *, char *);
void	my_msz(t_server *, t_player *, char *);
void	my_bct(t_server *, t_player *, char *);
void	my_mct(t_server *, t_player *, char *);
void	my_tna(t_server *, t_player *, char *);
void	my_ppo(t_server *, t_player *, char *);
void	my_plv(t_server *, t_player *, char *);
void	my_pin(t_server *, t_player *, char *);
void	my_sgt(t_server *, t_player *, char *);
void	my_sst(t_server *, t_player *, char *);
void	graphic_instr(t_server *, t_player *, int *, e_ginstr);
void	graphic_instr_all(t_server *, int *, e_ginstr);
void	msz(t_server *, t_player *, int *);
void	bct(t_server *, t_player *, int *);
void	tna(t_server *, t_player *, int *);
void	pnw(t_server *, t_player *, int *);
void	ppo(t_server *, t_player *, int *);
void	plv(t_server *, t_player *, int *);
void	pin(t_server *, t_player *, int *);
void	pex(t_server *, t_player *, int *);
void	pbc(t_server *, t_player *, int *);
void	pic(t_server *, t_player *, int *);
void	pie(t_server *, t_player *, int *);
void	pfk(t_server *, t_player *, int *);
void	pdr(t_server *, t_player *, int *);
void	pgt(t_server *, t_player *, int *);
void	pdi(t_server *, t_player *, int *);
void	enw(t_server *, t_player *, int *);
void	eht(t_server *, t_player *, int *);
void	ebo(t_server *, t_player *, int *);
void	edi(t_server *, t_player *, int *);
void	sgt(t_server *, t_player *, int *);
void	seg(t_server *, t_player *, int *);
void	smg(t_server *, t_player *, int *);
void	suc(t_server *, t_player *, int *);
void	sbp(t_server *, t_player *, int *);

#endif
