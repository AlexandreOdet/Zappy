/*
** my_avance.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun  3 11:06:09 2015 Coudray Colin
** Last update Mon Jun 22 10:36:28 2015 Coudray Colin
*/

#include "server.h"

typedef void		(*f_move)(t_server *serv, t_player *player);

static void		my_move_up(t_server *serv, t_player *player)
{
  int			x;
  int			y;

  x = player->pos % serv->width;
  y = player->pos / serv->width;
  y -= 1;
  if (y == -1)
    y = serv->height - 1;
  move_player(serv, player, player->pos, COORD(x, y));
}

static void		my_move_right(t_server *serv, t_player *player)
{
  int			x;
  int			y;

  x = player->pos % serv->width;
  y = player->pos / serv->width;
  x += 1;
  if (x == serv->width)
    x = 0;
  move_player(serv, player, player->pos, COORD(x, y));
}

static void		my_move_down(t_server *serv, t_player *player)
{
  int			x;
  int			y;

  x = player->pos % serv->width;
  y = player->pos / serv->width;
  y += 1;
  if (y == serv->height)
    y = 0;
  move_player(serv, player, player->pos, COORD(x, y));
}

static void		my_move_left(t_server *serv, t_player *player)
{
  int			x;
  int			y;

  x = player->pos % serv->width;
  y = player->pos / serv->width;
  x -= 1;
  if (x == -1)
    x = serv->width - 1;
  move_player(serv, player, player->pos, COORD(x, y));
}

static f_move		g_ftab[] =
  {
    &my_move_up,
    &my_move_left,
    &my_move_down,
    &my_move_right
  };

void			my_avance(t_server *serv,
				  t_player *player,
				  char *buff __attribute__((__unused__)))
{
  g_ftab[player->side](serv, player);
  buff_append(player->wrbuff, "ok\n", 3);
  graphic_instr_all(serv, (int *)player, PPO);
}
