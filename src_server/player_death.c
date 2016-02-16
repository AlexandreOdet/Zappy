/*
** player_death.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Tue Jun  9 12:55:22 2015 Coudray Colin
** Last update Thu Jun 25 16:41:47 2015 Coudray Colin
*/

#include <unistd.h>
#include "server.h"

void	player_death(t_server *serv, t_player *player)
{
  remove_player_from_case(serv, player, player->pos);
  buff_append(player->wrbuff, "mort\n", 5);
  register_event(serv, KILL_PLAYER, 0, (void *)player);
  graphic_instr_all(serv, &player->num, PDI);
}
