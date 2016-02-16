/*
** init_fdsets.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri May 29 12:14:15 2015 Coudray Colin
** Last update Fri Jun 19 11:40:29 2015 Coudray Colin
*/

#include <sys/select.h>
#include <stdlib.h>
#include "server.h"

static void	init_fdsets_team(t_player *player,
				 fd_set *rdfd,
				 fd_set *wrfd,
				 int *higher_fd)
{
  t_player	*tmp;

  tmp = player;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, rdfd);
      if (tmp->wrbuff->size > 0)
	FD_SET(tmp->fd, wrfd);
      if (tmp->fd > *higher_fd)
        *higher_fd = tmp->fd;
      tmp = tmp->next;
    }
}

int		init_fdsets(t_server *serv,
			    fd_set *rdfd,
			    fd_set *wrfd,
			    struct timeval *tv)
{
  int		higher_fd;
  t_team	*tmp;

  FD_ZERO(rdfd);
  FD_ZERO(wrfd);
  FD_SET(serv->fd, rdfd);
  higher_fd = serv->fd;
  init_fdsets_team(serv->tmp_player, rdfd, wrfd, &higher_fd);
  init_fdsets_team(serv->graphics, rdfd, wrfd, &higher_fd);
  tmp = serv->teams;
  while (tmp != NULL)
    {
      init_fdsets_team(tmp->players, rdfd, wrfd, &higher_fd);
      tmp = tmp->next;
    }
  tv->tv_sec = 0;
  tv->tv_usec = 20000;
  return (higher_fd);
}
