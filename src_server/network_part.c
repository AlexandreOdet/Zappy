/*
** network_part.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri May 29 12:16:07 2015 Coudray Colin
** Last update Wed Jul  1 11:19:18 2015 Coudray Colin
*/

#include <sys/select.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

void			main_loop_network(t_server *serv,
					  fd_set *rdfd,
					  fd_set *wrfd,
					  struct timeval *tv)
{
  t_team		*tmp;
  t_player		*tmp2;
  int			higher_fd;

  higher_fd = init_fdsets(serv, rdfd, wrfd, tv);
  if (select(higher_fd + 1, rdfd, wrfd, NULL, tv) == -1)
    return ;
  if (FD_ISSET(serv->fd, rdfd))
    accept_new_client(serv);
  tmp = serv->teams;
  while (tmp != NULL)
    {
      tmp2 = tmp->players;
      while (tmp2 != NULL)
	{
	  higher_fd = 1;
          if (FD_ISSET(tmp2->fd, rdfd))
            higher_fd = player_read(serv, &tmp->players, &tmp2);
          if (higher_fd && tmp2 && FD_ISSET(tmp2->fd, wrfd))
            player_write(serv, tmp2);
          if (higher_fd && tmp2)
            tmp2 = tmp2->next;
        }
      tmp = tmp->next;
    }
}

void			new_player_network(t_server *serv, fd_set *rdfd, fd_set *wrfd)
{
  t_player		*tmp;
  int			r;

  tmp = serv->tmp_player;
  r = 1;
  while (tmp != NULL && g_exit == 0)
    {
      if (FD_ISSET(tmp->fd, rdfd))
	r = player_read(serv, &serv->tmp_player, &tmp);
      if (r && tmp && FD_ISSET(tmp->fd, wrfd))
        player_write(serv, tmp);
      if (r && tmp)
        tmp = tmp->next;
    }
}

void			graphic_network(t_server *serv, fd_set *rdfd, fd_set *wrfd)
{
  t_player		*tmp;
  int			r;

  tmp = serv->graphics;
  r = 1;
  while (tmp != NULL && g_exit == 0)
    {
      if (FD_ISSET(tmp->fd, rdfd))
        r = player_read(serv, &serv->graphics, &tmp);
      if (r && tmp && FD_ISSET(tmp->fd, wrfd))
        player_write(serv, tmp);
      if (r && tmp)
        tmp = tmp->next;
    }
}
