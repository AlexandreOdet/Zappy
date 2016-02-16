/*
** remove_player_from_events.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun 26 12:04:54 2015 Coudray Colin
** Last update Wed Jul  1 12:03:59 2015 Coudray Colin
*/

#include <stdlib.h>
#include "server.h"

typedef void	(*f_clean_event)(t_server *, t_player *, t_event *);

typedef struct
{
  f_event	what;
  f_clean_event	cleaner;
} t_map;

static void	cleaner_nothing_to_clean(t_server *serv,
					 t_player *player,
					 t_event *event)
{
  (void)serv, (void)player, (void)event;
}

static void	cleaner_lvlup(t_server *serv __attribute__((__unused__)),
			      t_player *to_kill,
			      t_event *event)
{
  t_gen         *tmp2;
  t_gen         *tmp3;

  tmp2 = (t_gen *)event->data;
  while (tmp2->next && tmp2->next->data != to_kill)
    tmp2 = tmp2->next;
  if (tmp2->next)
    {
      tmp3 = tmp2->next;
      tmp2->next = tmp2->next->next;
      free(tmp3);
    }
}

static t_map g_ftab[] =
  {
    {&pop_food, &cleaner_nothing_to_clean},
    {&kill_player, &cleaner_nothing_to_clean},
    {&egg_hatching, &cleaner_nothing_to_clean},
    {&lvlup, &cleaner_lvlup},
    {&end_fork, &cleaner_nothing_to_clean}
  };

void            remove_player_from_events(t_server *serv, t_player *to_kill)
{
  t_event       *tmp;
  int		i;

  tmp = serv->events;
  while (tmp != NULL)
    {
      i = 0;
      while (i * sizeof(t_map) < sizeof(g_ftab) && g_ftab[i].what != tmp->what)
	i += 1;
      if (i * sizeof(t_map) < sizeof(g_ftab))
	g_ftab[i].cleaner(serv, to_kill, tmp);
      tmp = tmp->next;
    }
}
