/*
** free_player.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun 10 15:00:13 2015 Coudray Colin
** Last update Sat Jun 27 16:38:25 2015 Coudray Colin
*/

#include <stdlib.h>
#include <unistd.h>
#include "server.h"

static void	free_buff(t_buff *buff)
{
  if (buff->buff != NULL)
    free(buff->buff);
  free(buff);
}

void		free_player(t_player **list, t_player *to_free)
{
  t_player	*tmp;

  if (list != NULL && *list != NULL)
    {
      if (*list == to_free)
	*list = (*list)->next;
      else
	{
	  tmp = *list;
	  while (tmp->next && tmp->next != to_free)
	    tmp = tmp->next;
	  tmp->next = tmp->next->next;
	}
    }
  close(to_free->fd);
  free_buff(to_free->rdbuff);
  free_buff(to_free->wrbuff);
  free(to_free);
}
