/*
** my_connect_nbr.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun  3 11:06:09 2015 Coudray Colin
** Last update Wed Jun 10 11:53:51 2015 Coudray Colin
*/

#include "server.h"

void	my_connect_nbr(t_server *serv __attribute__((__unused__)),
		       t_player *player,
		       char *unused __attribute__((__unused__)))
{
  char	buff[512];
  int	len;

  len = snprintf(buff, sizeof(buff), "%d\n",
		 player->team->team_size - nb_player_in_team(player->team));
  buff_append(player->wrbuff, buff, len);
}
