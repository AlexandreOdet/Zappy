/*
** pop_food.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Tue Jun  9 13:19:58 2015 Coudray Colin
** Last update Sun Jul  5 17:26:29 2015 Coudray Colin
*/

#include <stdlib.h>
#include "server.h"

void		pop_food(t_server *serv,
			 void *useless_null_pointer __attribute__((__unused__)))
{
  int		i;
  unsigned int	j;

  i = 0;
  while (i < serv->width * serv->height)
    {
      j = 0;
      while (j < NB_CONTENT)
	{
	  if (j == FOOD)
	    {
	      if (rand() % 3 == 0 && serv->map[i].content[j] < 42)
		serv->map[i].content[j] += 3;
	    }
	  else
	    if (rand() % ((serv->map[i].content[j] + 6) * 15) == 0 &&
		serv->map[i].content[j] < 4)
	      serv->map[i].content[j] += 1;
	  j += 1;
	}
      i += 1;
    }
  register_event(serv, POP_FOOD, 500.0 / serv->time_unit, NULL);
}
