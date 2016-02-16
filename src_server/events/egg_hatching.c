/*
** egg_hatching.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun 10 12:57:47 2015 Coudray Colin
** Last update Wed Jul  1 17:43:18 2015 Coudray Colin
*/

#include <stdlib.h>
#include "server.h"

static void	pop_egg(t_server *serv, t_egg *to_pop)
{
  t_egg		*tmp;

  tmp = serv->eggs;
  if (to_pop == serv->eggs)
    serv->eggs = serv->eggs->next;
  else
    {
      while (tmp && tmp->next && tmp->next != to_pop)
	tmp = tmp->next;
      tmp->next = tmp->next->next;
    }
}

void		egg_hatching(t_server *serv,
			     void *data)
{
  t_egg		*hatch;
  char          buff[512];
  int           len;

  hatch = (t_egg *)data;
  pop_egg(serv, hatch);
  if (hatch->chick != NULL)
    {
      gettimeofday(&hatch->chick->death, NULL);
      add_time(&hatch->chick->death, 1260.0 / serv->time_unit);
      hatch->chick->pos = hatch->pos;
      add_player(&hatch->team->players, hatch->chick);
      add_player_to_case(serv, hatch->chick, hatch->pos);
      len = snprintf(buff, sizeof(buff), "%d\n%d %d\n",
		     hatch->team->team_size - nb_player_in_team(hatch->team),
		     serv->width, serv->height);
      buff_append(hatch->chick->wrbuff, buff, len);
      graphic_instr_all(serv, (int *)hatch->chick, PNW);
      graphic_instr_all(serv, (int *)hatch->chick, PIN);
      graphic_instr_all(serv, &hatch->num_egg, EHT);
    }
  else
    graphic_instr_all(serv, &hatch->num_egg, EDI);
  free(hatch);
}
