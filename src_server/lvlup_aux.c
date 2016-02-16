/*
** lvlup_aux.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jul  1 11:57:14 2015 Coudray Colin
** Last update Wed Jul  1 16:51:45 2015 Coudray Colin
*/

#include "server.h"

extern t_lvlup  g_lvltab[];

void		consum_stones(t_server *serv, int level, int pos)
{
  serv->map[pos].content[LINEMATE] -=
    g_lvltab[level - 1].requirement[LINEMATE];
  serv->map[pos].content[SIBUR] -=
    g_lvltab[level - 1].requirement[SIBUR];
  serv->map[pos].content[THYSTAME] -=
    g_lvltab[level - 1].requirement[THYSTAME];
  serv->map[pos].content[DERAUMERE] -=
    g_lvltab[level - 1].requirement[DERAUMERE];
  serv->map[pos].content[MENDIANE] -=
    g_lvltab[level - 1].requirement[MENDIANE];
  serv->map[pos].content[PHIRAS] -=
    g_lvltab[level - 1].requirement[PHIRAS];
}

void		broadcast_incantation_result(t_server *serv, long pos, int res)
{
  t_player	*gr;
  int		len;
  char		buff[512];

  len = snprintf(buff, sizeof(buff), "pie %ld %ld %d\n",
                 pos % serv->width,
                 pos / serv->width, res);
  gr = serv->graphics;
  while (gr != NULL)
    {
      buff_append(gr->wrbuff, buff, len);
      gr = gr->next;
    }
}

void		say_bye_to_players(t_server *serv)
{
  t_team	*tmp;
  t_player	*tmp2;

  tmp = serv->teams;
  while (tmp != NULL)
    {
      tmp2 = tmp->players;
      while (tmp2 != NULL)
	{
	  buff_append(tmp2->wrbuff, "mort\n", 5);
	  tmp2 = tmp2->next;
	}
      tmp = tmp->next;
    }
}
