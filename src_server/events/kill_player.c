/*
** kill_player.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Tue Jun  9 13:08:27 2015 Coudray Colin
** Last update Fri Jun 26 12:05:17 2015 Coudray Colin
*/

#include "server.h"

void		kill_player(t_server *serv,
			    void *data)
{
  t_player	*to_kill;

  to_kill = (t_player *)data;
  remove_player_from_events(serv, to_kill);
  free_player(&to_kill->team->players, to_kill);
}
