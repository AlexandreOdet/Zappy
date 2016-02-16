/*
** place_player.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon Jun  8 14:02:05 2015 Coudray Colin
** Last update Wed Jul  1 11:11:41 2015 Coudray Colin
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

int		add_player_to_case(t_server *serv, t_player *player, int coord)
{
  t_gen		*new;

  if ((new = malloc(sizeof(t_gen))) == NULL)
    return (1);
  bzero(new, sizeof(t_gen));
  new->data = (void *)player;
  player->pos = coord;
  if (serv->map[coord].players == NULL)
    serv->map[coord].players = new;
  else
    {
      new->next = serv->map[coord].players;
      serv->map[coord].players = new;
    }
  return (0);
}

void		remove_player_from_case(t_server *serv,
					t_player *player,
					int coord)
{
  t_gen		*tmp;
  t_gen		*to_free;

  player->pos = -1;
  if (serv->map[coord].players == NULL)
    return ;
  else if (serv->map[coord].players->data == (void *)player)
    {
      to_free = serv->map[coord].players;
      serv->map[coord].players = serv->map[coord].players->next;
    }
  else
    {
      tmp = serv->map[coord].players;
      while (tmp->next && tmp->next->data != (void *)player)
	tmp = tmp->next;
      to_free = tmp->next;
      if (tmp->next != NULL)
	tmp->next = tmp->next->next;
    }
  free(to_free);
}

int		move_player(t_server *serv,
			    t_player *player,
			    int old_coord,
			    int new_coord)
{
  remove_player_from_case(serv, player, old_coord);
  return (add_player_to_case(serv, player, new_coord));
}

void		place_player(t_server *serv, t_player *new)
{
  int		x;
  int		y;
  char		buff[512];
  int		len;

  x = rand() % serv->width;
  y = rand() % serv->height;
  add_player_to_case(serv, new, COORD(x, y));
  len = snprintf(buff, sizeof(buff), "%d\n%d %d\n",
		 new->team->team_size - nb_player_in_team(new->team),
		 serv->width,
		 serv->height);
  buff_append(new->wrbuff, buff, len);
  graphic_instr_all(serv, (int *)new, PNW);
  graphic_instr_all(serv, (int *)new, PIN);
}
