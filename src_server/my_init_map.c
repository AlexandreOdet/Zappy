/*
** my_init_map.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun  5 11:07:51 2015 Coudray Colin
** Last update Wed Jul  1 11:16:27 2015 Coudray Colin
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

int	my_init_map(t_server *serv)
{
  int	i;
  int	tmp;

  i = 0;
  if ((serv->map = malloc(serv->width * serv->height *
			  sizeof(t_case))) == NULL)
    return (1);
  bzero(serv->map, serv->width * serv->height * sizeof(t_case));
  while (i < serv->width * serv->height)
    {
      tmp = rand() % 3;
      if (tmp == 0)
	serv->map[i].content[FOOD] += rand() % 3;
      i += 1;
    }
  register_event(serv, POP_FOOD, 0, NULL);
  return (0);
}
