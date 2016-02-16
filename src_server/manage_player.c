/*
** manage_player.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Tue May 12 15:38:07 2015 Coudray Colin
** Last update Wed Jul  1 22:03:09 2015 Coudray Colin
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

void		add_player(t_player **list, t_player *new_client)
{
  if (*list == NULL)
    {
      *list = new_client;
    }
  else
    {
      new_client->next = *list;
      *list = new_client;
    }
}

int		add_player_in_egg(t_server *serv, t_player *new)
{
  t_egg		*tmp;
  int		i;

  tmp = serv->eggs;
  while (tmp != NULL)
    {
      if (tmp->chick == NULL && tmp->team == new->team)
	{
	  tmp->chick = new;
	  graphic_instr_all(serv, &tmp->num_egg, EBO);
	  return (1);
	}
      i -= 1;
      tmp = tmp->next;
    }
  return (0);
}

int		add_player_to_team(t_server *serv, t_player *new, char *team_name)
{
  t_team	*tmp;
  static int	uniqid = 1;

  tmp = serv->teams;
  remove_player_from_team(&serv->tmp_player, new);
  while (tmp != NULL && strcmp(tmp->name, team_name) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    {
      free_player(NULL, new);
      return (-1);
    }
  new->num = uniqid++;
  new->team = tmp;
  if (add_player_in_egg(serv, new) == 1)
    return (1);
  if (nb_player_in_team(tmp) >= tmp->team_size)
    {
      free_player(NULL, new);
      return (-1);
    }
  gettimeofday(&new->death, NULL);
  add_time(&new->death, 1260.0 / serv->time_unit);
  add_player(&tmp->players, new);
  return (0);
}

void		add_player_to_graphic(t_server *serv, t_player *new)
{
  int		i;
  t_team	*tmp;
  t_player	*tmp2;

  remove_player_from_team(&serv->tmp_player, new);
  add_player(&serv->graphics, new);
  graphic_instr(serv, new, NULL, MSZ);
  graphic_instr(serv, new, NULL, SGT);
  i = -1;
  while (++i < serv->width * serv->height)
    graphic_instr(serv, new, &i, BCT);
  graphic_instr(serv, new, NULL, TNA);
  tmp = serv->teams;
  while (tmp != NULL)
    {
      tmp2 = tmp->players;
      while (tmp2 != NULL)
	{
	  graphic_instr(serv, new, (int *)tmp2, PNW);
	  tmp2 = tmp2->next;
	}
      tmp = tmp->next;
    }
  declare_eggs_to_graphic(serv, new);
}

void		remove_player_from_team(t_player **team, t_player *player)
{
  t_player	*tmp;

  tmp = *team;
  if (*team == player)
    {
      *team = player->next;
    }
  else
    {
      while (tmp->next && tmp->next != player)
	tmp = tmp->next;
      if (tmp->next != NULL)
	tmp->next = tmp->next->next;
    }
  player->next = NULL;
}
