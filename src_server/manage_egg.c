/*
** declare_eggs_to_graphic.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon Jun 22 09:57:53 2015 Coudray Colin
** Last update Thu Jun 25 11:36:07 2015 Coudray Colin
*/

#include "server.h"

int	count_egg(t_server *serv)
{
  t_egg	*tmp;
  int	i;

  i = 0;
  tmp = serv->eggs;
  while (tmp != NULL)
    {
      i += 1;
      tmp = tmp->next;
    }
  return (i);
}

void	declare_eggs_to_graphic(t_server *serv, t_player *client)
{
  t_egg	*tmp;
  int	len;
  char	buff[512];
  int	i;

  tmp = serv->eggs;
  i = count_egg(serv);
  while (tmp != NULL)
    {
      len = snprintf(buff, sizeof(buff), "enw %d %d %d %d\n",
		     i, tmp->num_hen, tmp->pos % serv->width, tmp->pos / serv->width);
      buff_append(client->wrbuff, buff, len);
      i -= 1;
      tmp = tmp->next;
    }
}
