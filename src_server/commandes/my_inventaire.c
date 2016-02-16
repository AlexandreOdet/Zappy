/*
** my_inventaire.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun  3 11:06:09 2015 Coudray Colin
** Last update Sat Jun 27 20:47:34 2015 Coudray Colin
*/

#include "server.h"

void	my_inventaire(t_server *serv,
		      t_player *player,
		      char *buff __attribute__((__unused__)))
{
  char	tmp[512];
  int	len;

  len = snprintf(tmp, sizeof(tmp),
		 "{nourriture %d,linemate %d,deraumere %d,\
sibur %d,mendiane %d,phiras %d,thystame %d}\n\n",
		 (int)((sub_time(&player->death, &serv->now) * serv->time_unit)
		       / DELAY_FOOD),
		 player->inventory[LINEMATE],
		 player->inventory[DERAUMERE],
		 player->inventory[SIBUR],
		 player->inventory[MENDIANE],
		 player->inventory[PHIRAS],
		 player->inventory[THYSTAME]);
  buff_append(player->wrbuff, tmp, len);
}
