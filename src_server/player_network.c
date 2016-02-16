/*
** player_network.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon Jun  1 11:29:23 2015 Coudray Colin
** Last update Wed Jul  1 20:58:00 2015 Coudray Colin
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

int		player_read(t_server *serv, t_player **list, t_player **player)
{
  int		r;
  char		buff[512];

  r = read((*player)->fd, buff, sizeof(buff));
  if (r <= 0)
    {
      remove_player_from_events(serv, *player);
      remove_player_from_case(serv, *player, (*player)->pos);
      graphic_instr_all(serv, &(*player)->num, PDI);
      free_player(list, *player);
      *player = NULL;
      return (0);
    }
  buff_append((*player)->rdbuff, buff, r);
  return (1);
}

void		player_write(t_server *serv,
			     t_player *player)
{
  int		w;
  t_buff	buff;

  if ((w = write(player->fd, player->wrbuff->buff,
		 player->wrbuff->size)) == -1)
    return ;
  if (serv->verbose)
    {
      bzero(&buff, sizeof(t_buff));
      buff_append(&buff, player->wrbuff->buff, w);
      buff_append(&buff, "\0", 1);
      printf("%sSend to %d : %s\n", KGRN, player->num, buff.buff);
      if (buff.buff != NULL)
	free(buff.buff);
    }
  buff_remove(player->wrbuff, w);
}
