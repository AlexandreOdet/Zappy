/*
** my_voir.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun  3 11:06:09 2015 Coudray Colin
** Last update Wed Jul  1 16:11:46 2015 Coudray Colin
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

void		adjust_coord(t_server *serv, int *x, int *y)
{
  *x %= serv->width;
  *x = (*x < 0) ? serv->width + *x : *x;
  *y %= serv->height;
  *y = (*y < 0) ? serv->width + *y : *y;
}

int		case_has_player(t_server *serv, t_player *player, int pos)
{
  t_gen		*tmp;
  int		i;

  (void)player;
  tmp = serv->map[pos].players;
  i = 0;
  while (tmp != NULL)
    {
      i += 1;
      tmp = tmp->next;
    }
  return (i);
}

void		get_case_item(int nb, char *to_append, t_buff *buff)
{
  int		j;

  j = 0;
  while (j++ < nb)
    buff_append(buff, to_append, strlen(to_append));
}

void		get_case_content(t_server *serv,
				 t_player *player,
				 int pos,
				 t_buff *buff)
{
  int		tmp;

  if (serv->map[pos].content[FOOD] != 0)
    get_case_item(serv->map[pos].content[FOOD], " nourriture", buff);
  if (serv->map[pos].content[LINEMATE] != 0)
    get_case_item(serv->map[pos].content[LINEMATE], " linemate", buff);
  if (serv->map[pos].content[DERAUMERE] != 0)
    get_case_item(serv->map[pos].content[DERAUMERE], " deraumere", buff);
  if (serv->map[pos].content[SIBUR] != 0)
    get_case_item(serv->map[pos].content[SIBUR], " sibur", buff);
  if (serv->map[pos].content[MENDIANE] != 0)
    get_case_item(serv->map[pos].content[MENDIANE], " mendiane", buff);
  if (serv->map[pos].content[PHIRAS] != 0)
    get_case_item(serv->map[pos].content[PHIRAS], " phiras", buff);
  if (serv->map[pos].content[THYSTAME] != 0)
    get_case_item(serv->map[pos].content[THYSTAME], " thystame", buff);
  if ((tmp = case_has_player(serv, player, pos)) > 0)
    get_case_item(tmp, " joueur", buff);
}

void		my_voir(t_server *serv,
			t_player *player,
			char *useless __attribute__((__unused__)))
{
  int		tmp_pos;
  t_buff	tmp_buff;
  int		b;

  bzero(&tmp_buff, sizeof(t_buff));
  buff_append(&tmp_buff, "{", 1);
  b = 0;
  while ((tmp_pos = get_next_case(serv, player)) != -1)
    {
      if (b++ != 0)
	buff_append(&tmp_buff, ",", 1);
      get_case_content(serv, player, tmp_pos, &tmp_buff);
    }
  buff_append(&tmp_buff, "}\n\n", 3);
  buff_append(player->wrbuff, tmp_buff.buff, tmp_buff.size);
  if (tmp_buff.buff != NULL)
    free(tmp_buff.buff);
}
