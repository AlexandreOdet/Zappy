/*
** event.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun  5 14:18:54 2015 Coudray Colin
** Last update Sun Jul  5 20:26:51 2015 Coudray Colin
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"

static f_event	g_ftab[] =
  {
    &pop_food,
    &kill_player,
    &egg_hatching,
    &lvlup,
    &end_fork,
    &finish_game
  };

int		register_event(t_server *serv,
			       e_event num_evt,
			       float delay,
			       void *data)
{
  t_event	*new;
  t_event	*tmp;

  if ((new = malloc(sizeof(t_event))) == NULL)
    return (1);
  bzero(new, sizeof(t_event));
  gettimeofday(&new->when, NULL);
  add_time(&new->when, delay);
  new->what = g_ftab[num_evt];
  new->data = data;
  if (serv->events == NULL)
    serv->events = new;
  else
    {
      tmp = serv->events;
      while (tmp->next != NULL &&
	     my_timediff(&tmp->next->when, &new->when) == -1)
	tmp = tmp->next;
      new->next = tmp->next;
      tmp->next = new;
    }
  return (0);
}

void		pop_event(t_server *serv, t_event *evt)
{
  t_event	*tmp;

  if (serv->events == evt)
    serv->events = serv->events->next;
  else
    {
      tmp = serv->events;
      while (tmp->next != NULL && evt != tmp->next)
	tmp = tmp->next;
      if (tmp->next != NULL)
	tmp->next = tmp->next->next;
    }
  free(evt);
}

void		handle_events(t_server *serv)
{
  t_event	*tmp;
  t_event	*tmp2;

  tmp = serv->events;
  while (tmp != NULL)
    {
      if (my_timediff(&serv->now, &tmp->when) == 1)
        {
          tmp->what(serv, tmp->data);
          tmp2 = tmp->next;
          pop_event(serv, tmp);
          tmp = tmp2;
        }
      else
        tmp = tmp->next;
    }
}
