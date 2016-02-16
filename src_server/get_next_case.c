/*
** get_next_case.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun 12 15:42:35 2015 Coudray Colin
** Last update Wed Jun 17 14:33:37 2015 Coudray Colin
*/

#include "server.h"

typedef int     (*f_see)(t_server *, t_player *);

static int      get_next_case_up(t_server *serv, t_player *player)
{
  static int    x = 0;
  static int    y = 0;
  int           posx;
  int           posy;

  if (-y > player->level)
    {
      x = 0;
      y = 0;
      return (-1);
    }
  posx = player->pos % serv->width;
  posy = player->pos / serv->width;
  posx += x;
  posy += y;
  adjust_coord(serv, &posx, &posy);
  if ((x == 0 && y == 0) || x == (-y))
    {
      y -= 1;
      x = y;
    }
  else
    x += 1;
  return (COORD(posx, posy));
}

static int      get_next_case_right(t_server *serv, t_player *player)
{
  static int    x = 0;
  static int    y = 0;
  int           posx;
  int           posy;

  if (x > player->level)
    {
      x = 0;
      y = 0;
      return (-1);
    }
  posx = player->pos % serv->width;
  posy = player->pos / serv->width;
  posx += x;
  posy += y;
  adjust_coord(serv, &posx, &posy);
  if ((x == 0 && y == 0) || y == (x))
    {
      x += 1;
      y = -x;
    }
  else
    y += 1;
  return (COORD(posx, posy));
}

static int      get_next_case_down(t_server *serv, t_player *player)
{
  static int    x = 0;
  static int    y = 0;
  int           posx;
  int           posy;

  if (y > player->level)
    {
      x = 0;
      y = 0;
      return (-1);
    }
  posx = player->pos % serv->width;
  posy = player->pos / serv->width;
  posx += x;
  posy += y;
  adjust_coord(serv, &posx, &posy);
  if ((x == 0 && y == 0) || x == (y))
    {
      y += 1;
      x = -y;
    }
  else
    x += 1;
  return (COORD(posx, posy));
}

static int      get_next_case_left(t_server *serv, t_player *player)
{
  static int    x = 0;
  static int    y = 0;
  int           posx;
  int           posy;

  if (-x > player->level)
    {
      x = 0;
      y = 0;
      return (-1);
    }
  posx = player->pos % serv->width;
  posy = player->pos / serv->width;
  posx += x;
  posy += y;
  adjust_coord(serv, &posx, &posy);
  if ((x == 0 && y == 0) || y == (-x))
    {
      x -= 1;
      y = x;
    }
  else
    y += 1;
  return (COORD(posx, posy));
}

static f_see    g_ftab[] =
  {
    &get_next_case_up,
    &get_next_case_left,
    &get_next_case_down,
    &get_next_case_right
  };

int             get_next_case(t_server *serv, t_player *player)
{
  return (g_ftab[player->side](serv, player));
}
