/*
** instr_player_info.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Sun Jun 21 00:18:12 2015 Coudray Colin
** Last update Fri Jul  3 18:43:37 2015 Coudray Colin
*/

#include "server.h"

static int	adapt_side(int x)
{
  return (x == LEFTSIDE ? RIGHTSIDE :
	  (x == RIGHTSIDE ? LEFTSIDE : x));
}

void		pnw(t_server *serv,
		    t_player *client,
		    int *to_cast)
{
  char		buff[512];
  int		len;
  t_player	*tmp2;

  tmp2 = (t_player *)to_cast;
  len = snprintf(buff, sizeof(buff), "pnw %d %d %d %d %d %s\n",
		 tmp2->num, tmp2->pos % serv->width, tmp2->pos / serv->width,
		 adapt_side(tmp2->side) + 1, tmp2->level, tmp2->team->name);
  buff_append(client->wrbuff, buff, len);
}

void		ppo(t_server *serv,
		    t_player *client,
		    int *to_cast)
{
  char		buff[512];
  int		len;
  t_player	*tmp2;

  tmp2 = (t_player *)to_cast;
  len = snprintf(buff, sizeof(buff), "ppo %d %d %d %d\n",
		 tmp2->num, tmp2->pos % serv->width, tmp2->pos / serv->width,
		 adapt_side(tmp2->side) + 1);
  buff_append(client->wrbuff, buff, len);
}

void		plv(t_server *serv __attribute__((__unused__)),
		    t_player *client,
		    int *to_cast)
{
  t_player	*tmp2;
  char		buff[512];
  int		len;

  tmp2 = (t_player *)to_cast;
  len = snprintf(buff, sizeof(buff), "plv %d %d\n",
		 tmp2->num, tmp2->level);
  buff_append(client->wrbuff, buff, len);
}

void		pin(t_server *serv,
		    t_player *client,
		    int *to_cast)
{
  char		buff[512];
  int		len;
  t_player	*tmp2;

  tmp2 = (t_player *)to_cast;
  len = snprintf(buff, sizeof(buff),
		 "pin %d %d %d %d %d %d %d %d %d %d\n",
		 tmp2->num, tmp2->pos % serv->width, tmp2->pos / serv->width,
		 (int)((sub_time(&tmp2->death, &serv->now) * serv->time_unit)
		       / DELAY_FOOD),
		 tmp2->inventory[LINEMATE], tmp2->inventory[DERAUMERE],
		 tmp2->inventory[SIBUR], tmp2->inventory[MENDIANE],
		 tmp2->inventory[PHIRAS], tmp2->inventory[THYSTAME]);
  buff_append(client->wrbuff, buff, len);
}
