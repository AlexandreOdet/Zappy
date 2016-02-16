/*
** manage_team.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon May 11 14:47:56 2015 Coudray Colin
** Last update Mon Jun  1 11:13:42 2015 Coudray Colin
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

void		add_team(t_server *serv, char *name)
{
  t_team	*new;
  t_team	*tmp;

  if ((new = malloc(sizeof(t_team))) == NULL)
    exit(EXIT_FAILURE);
  bzero(new, sizeof(t_team));
  new->name = name;
  new->team_size = serv->team_size;
  if (serv->teams == NULL)
    serv->teams = new;
  else
    {
      tmp = serv->teams;
      while (tmp->next)
	{
	  if (strcmp(tmp->name, name) == 0 || strcmp(tmp->next->name, name) == 0)
	    {
	      free(new);
	      return ;
	    }
	  tmp = tmp->next;
	}
      tmp->next = new;
    }
}

int		nb_player_in_team(t_team *team)
{
  t_player	*tmp;
  int		i;

  i = 0;
  tmp = team->players;
  while (tmp != NULL)
    {
      i += 1;
      tmp = tmp->next;
    }
  return (i);
}

int		my_nb_team(t_team *teams)
{
  t_team	*tmp;
  int		retval;

  retval = 0;
  tmp = teams;
  while (tmp)
    {
      tmp = tmp->next;
      retval += 1;
    }
  return (retval);
}
