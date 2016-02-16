/*
** my_droite.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun  3 11:06:09 2015 Coudray Colin
** Last update Mon Jun 22 10:38:27 2015 Coudray Colin
*/

#include "server.h"

void	my_droite(t_server *serv,
		  t_player *player,
		  char *buff __attribute__((__unused__)))
{
  if (player->side == RIGHTSIDE)
    player->side = DOWNSIDE;
  else if (player->side == LEFTSIDE)
    player->side = UPSIDE;
  else if (player->side == DOWNSIDE)
    player->side = LEFTSIDE;
  else
    player->side = RIGHTSIDE;
  buff_append(player->wrbuff, "ok\n", 3);
  graphic_instr_all(serv, (int *)player, PPO);
}
