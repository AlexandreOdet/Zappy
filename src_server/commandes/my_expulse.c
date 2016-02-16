/*
** my_expulse.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun  3 11:06:09 2015 Coudray Colin
** Last update Wed Jul  1 11:26:09 2015 Coudray Colin
*/

#include "server.h"

typedef void	(*f_expulse)(t_server *, t_player *, t_player *);

static void	my_expulse_top(t_server *serv,
			       t_player *drone,
			       t_player *victim)
{
  int		x;
  int		y;
  char		buff[512];
  int		len;

  x = victim->pos % serv->width;
  y = victim->pos / serv->width;
  y -= 1;
  adjust_coord(serv, &x, &y);
  move_player(serv, victim, victim->pos, COORD(x, y));
  len = snprintf(buff, sizeof(buff), "deplacement: %d\n",
		 get_direction(serv, drone, victim));
  buff_append(victim->wrbuff, buff, len);
}

static void	my_expulse_left(t_server *serv,
				t_player *drone,
				t_player *victim)
{
  int		x;
  int		y;
  char		buff[512];
  int		len;

  x = victim->pos % serv->width;
  y = victim->pos / serv->width;
  x -= 1;
  adjust_coord(serv, &x, &y);
  move_player(serv, victim, victim->pos, COORD(x, y));
  len = snprintf(buff, sizeof(buff), "deplacement: %d\n",
		 get_direction(serv, drone, victim));
  buff_append(victim->wrbuff, buff, len);
}

static void	my_expulse_down(t_server *serv,
				t_player *drone,
				t_player *victim)
{
  int		x;
  int		y;
  char		buff[512];
  int		len;

  x = victim->pos % serv->width;
  y = victim->pos / serv->width;
  y += 1;
  adjust_coord(serv, &x, &y);
  move_player(serv, victim, victim->pos, COORD(x, y));
  len = snprintf(buff, sizeof(buff), "deplacement: %d\n",
		 get_direction(serv, drone, victim));
  buff_append(victim->wrbuff, buff, len);
}

static void	my_expulse_right(t_server *serv,
				 t_player *drone,
				 t_player *victim)
{
  int		x;
  int		y;
  char		buff[512];
  int		len;

  x = victim->pos % serv->width;
  y = victim->pos / serv->width;
  x += 1;
  adjust_coord(serv, &x, &y);
  move_player(serv, victim, victim->pos, COORD(x, y));
  len = snprintf(buff, sizeof(buff), "deplacement: %d\n",
		 get_direction(serv, drone, victim));
  buff_append(victim->wrbuff, buff, len);
}

static f_expulse g_ftab[] =
  {
    &my_expulse_top,
    &my_expulse_left,
    &my_expulse_down,
    &my_expulse_right
  };

void		my_expulse(t_server *serv,
			   t_player *player,
			   char *buff __attribute__((__unused__)))
{
  t_gen		*tmp;

  if (serv->map[player->pos].players->data == (void *)player &&
      serv->map[player->pos].players->next == NULL)
    buff_append(player->wrbuff, "ko\n", 3);
  else
    {
      tmp = serv->map[player->pos].players;
      graphic_instr_all(serv, &player->num, PEX);
      while (tmp != NULL)
	{
	  if (tmp->data == (void *)player)
	    tmp = tmp->next;
	  else
	    {
	      g_ftab[player->side](serv, player, (t_player *)(tmp->data));
	      graphic_instr_all(serv, (int *)tmp->data, PPO);
	      tmp = serv->map[player->pos].players;
	    }
	}
      buff_append(player->wrbuff, "ok\n", 3);
    }
}
