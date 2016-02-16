/*
** instr_team.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Sun Jun 21 00:08:26 2015 Coudray Colin
** Last update Sun Jun 21 02:09:56 2015 Coudray Colin
*/

#include "server.h"

void		tna(t_server *serv,
		    t_player *client,
		    int *param __attribute__((__unused__)))
{
  t_team	*tmp;
  int		len;
  char		buff[512];

  tmp = serv->teams;
  while (tmp != NULL)
    {
      len = snprintf(buff, sizeof(buff), "tna %s\n", tmp->name);
      buff_append(client->wrbuff, buff, len);
      tmp = tmp->next;
    }
}
