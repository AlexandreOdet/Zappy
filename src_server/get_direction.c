/*
** get_direction.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon Jun 15 17:41:59 2015 Coudray Colin
** Last update Fri Jul  3 18:45:11 2015 Coudray Colin
*/

#include "server.h"

typedef struct
{
  int	x1;
  int	x2;
  int	y1;
  int	y2;
} t_intbag;

static int	adapt_from_side(int x, t_player *dest)
{
  return (((((x) - 1) + 2 * (dest->side == LEFTSIDE ?\
			     RIGHTSIDE : (dest->side == RIGHTSIDE ?
					  LEFTSIDE : dest->side))) % 8) + 1);
}

static int	get_direction_bot(t_player *dest, t_intbag *ints)
{
  if (ints->x1 < ints->x2)
    {
      if (ABS(ints->x1 - ints->x2) > ABS(ints->y1 - ints->y2))
	return (adapt_from_side(3, dest));
      else if (ABS(ints->x1 - ints->x2) < ABS(ints->y1 - ints->y2))
	return (adapt_from_side(1, dest));
      else
	return (adapt_from_side(2, dest));
    }
  else
    {
      if (ABS(ints->x1 - ints->x2) > ABS(ints->y1 - ints->y2))
	return (adapt_from_side(7, dest));
      else if (ABS(ints->x1 - ints->x2) < ABS(ints->y1 - ints->y2))
	return (adapt_from_side(1, dest));
      else
	return (adapt_from_side(8, dest));
    }
}

static int	get_direction_top(t_player *dest, t_intbag *ints)
{
  if (ints->x1 < ints->x2)
    {
      if (ABS(ints->x1 - ints->x2) > ABS(ints->y1 - ints->y2))
	return (adapt_from_side(3, dest));
      else if (ABS(ints->x1 - ints->x2) < ABS(ints->y1 - ints->y2))
	return (adapt_from_side(5, dest));
      else
	return (adapt_from_side(4, dest));
    }
  else
    {
      if (ABS(ints->x1 - ints->x2) > ABS(ints->y1 - ints->y2))
	return (adapt_from_side(7, dest));
      else if (ABS(ints->x1 - ints->x2) < ABS(ints->y1 - ints->y2))
	return (adapt_from_side(5, dest));
      else
	return (adapt_from_side(6, dest));
    }
}

int		get_direction(t_server *serv, t_player *src, t_player *dest)
{
  t_intbag	ints;

  if (src->pos == dest->pos)
    return (0);
  ints.x1 = src->pos % serv->width;
  ints.x2 = dest->pos % serv->width;
  ints.y1 = src->pos / serv->width;
  ints.y2 = dest->pos / serv->width;
  if (ABS(ints.x1 - ints.x2) > serv->width / 2)
    ints.x2 += ints.x1 > ints.x2 ? serv->width : -serv->width;
  if (ABS(ints.y1 - ints.y2) > serv->height / 2)
    ints.y2 += ints.y1 > ints.y2 ? serv->height : -serv->height;
  if (ints.y1 < ints.y2)
    return (get_direction_bot(dest, &ints));
  else
    return (get_direction_top(dest, &ints));
}
