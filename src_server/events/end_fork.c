/*
** end_fork.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon Jun 22 11:13:53 2015 Coudray Colin
** Last update Wed Jul  1 17:43:55 2015 Coudray Colin
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

static void	end_fork_aux(t_server *serv, t_egg *egg)
{
  t_player	*tmp;
  int		len;
  char		buff[512];

  tmp = serv->graphics;
  len = snprintf(buff, sizeof(buff), "enw %d %d %d %d\n",
		 egg->num_egg, egg->num_hen, egg->pos % serv->width,
		 egg->pos / serv->height);
  while (tmp != NULL)
    {
      buff_append(tmp->wrbuff, buff, len);
      tmp = tmp->next;
    }
}

void		end_fork(t_server *serv, void *data)
{
  t_player	*player;
  t_egg		*new;
  static int	num_egg = 1;

  player = (t_player *)data;
  if ((new = malloc(sizeof(t_egg))) != NULL)
    {
      bzero(new, sizeof(t_egg));
      player->team->team_size += 1;
      new->pos = player->pos;
      new->team = player->team;
      new->num_hen = player->num;
      new->num_egg = num_egg++;
      if (serv->eggs == NULL)
        serv->eggs = new;
      else
        {
          new->next = serv->eggs;
          serv->eggs = new;
        }
      register_event(serv, EGG_HATCHING, 600.0 / serv->time_unit, (void *)new);
      end_fork_aux(serv, new);
    }
}
