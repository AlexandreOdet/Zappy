/*
** my_fork.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun  3 11:06:09 2015 Coudray Colin
** Last update Mon Jun 22 11:17:31 2015 Coudray Colin
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"

void	my_fork(t_server *serv,
		t_player *player,
		char *buff __attribute__((__unused__)))
{
  register_event(serv, END_FORK, 42.0 / serv->time_unit, (void *)player);
  buff_append(player->wrbuff, "ok\n", 3);
  graphic_instr_all(serv, &player->num, PFK);
}
