/*
** clean_server.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Tue May 12 15:50:31 2015 Coudray Colin
** Last update Sat Jun 27 19:21:53 2015 Coudray Colin
*/

#include <unistd.h>
#include <stdlib.h>
#include "server.h"

static void	clean_team(t_player **team)
{
  t_player	*tmp;
  t_player	*tmp2;

  tmp = *team;
  while (tmp != NULL)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      free_player(team, tmp2);
    }
}

static void	clean_case(t_case c)
{
  t_gen		*tmp;
  t_gen		*tmp2;

  tmp = c.players;
  while (tmp != NULL)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      free(tmp2);
    }
}

static void	clean_eggs(t_server *serv)
{
  t_egg		*tmp;
  t_egg		*tmp2;

  tmp = serv->eggs;
  while (tmp != NULL)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      if (tmp2->chick)
	free_player(NULL, tmp2->chick);
      free(tmp2);
    }
}

static void	clean_events(t_server *serv)
{
  t_event	*tmp;
  t_event	*tmp2;
  t_gen		*ev;
  t_gen		*ev2;

  tmp = serv->events;
  while (tmp != NULL)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      if (tmp2->what == &lvlup)
	{
	  ev = ((t_gen *)tmp2->data);
	  while (ev != NULL)
	    {
	      ev2 = ev;
	      ev = ev->next;
	      free(ev2);
	    }
	}
      free(tmp2);
    }
}

void		clean_server(t_server *serv)
{
  t_team	*tmp;
  t_team	*to_free;
  int		i;

  close(serv->fd);
  i = -1;
  while (++i < serv->width * serv->height)
    clean_case(serv->map[i]);
  free(serv->map);
  tmp = serv->teams;
  clean_team(&serv->tmp_player);
  clean_team(&serv->graphics);
  clean_eggs(serv);
  clean_events(serv);
  while (tmp)
    {
      to_free = tmp;
      tmp = tmp->next;
      clean_team(&to_free->players);
      free(to_free);
    }
}
