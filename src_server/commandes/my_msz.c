/*
** my_msz.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun 19 19:02:42 2015 Coudray Colin
** Last update Mon Jun 22 11:54:04 2015 Coudray Colin
*/

#include "server.h"

void	my_msz(t_server *serv,
	       t_player *client,
	       char *str __attribute__((__unused__)))
{
  graphic_instr(serv, client, NULL, MSZ);
}
