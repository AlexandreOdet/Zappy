/*
** my_mct.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun 19 19:02:42 2015 Coudray Colin
** Last update Mon Jun 22 12:02:19 2015 Coudray Colin
*/

#include "server.h"

void	my_mct(t_server *serv,
	       t_player *client,
	       char *str __attribute__((__unused__)))
{
  int	i;

  i = -1;
  while (++i < serv->width * serv->height)
    graphic_instr(serv, client, &i, BCT);
}
