/*
** my_broadcast_texte.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun  3 11:06:09 2015 Coudray Colin
** Last update Thu Jun 25 15:24:23 2015 Coudray Colin
*/

#include "server.h"

static void	my_broadcast_texte_aux(t_server *serv,
				       t_player *player,
				       char *text)
{
  int		len;
  char		buff[512];
  t_player	*tmp;

  len = snprintf(buff, sizeof(buff), "pbc %d %s\n", player->num, text);
  tmp = serv->graphics;
  while (tmp != NULL)
    {
      buff_append(tmp->wrbuff, buff, len);
      tmp = tmp->next;
    }
}

void		my_broadcast_texte(t_server *serv,
			   t_player *player,
			   char *cmd)
{
  char		*text;
  t_team	*tmp;
  t_player	*tmp2;
  int		len;
  char		buff[512];

  text = get_second_word(cmd);
  tmp = serv->teams;
  while (tmp != NULL)
    {
      tmp2 = tmp->players;
      while (tmp2 != NULL)
	{
	  if (tmp2 != player)
	    {
	      len = snprintf(buff, sizeof(buff), "message %d,%s\n",
			     get_direction(serv, player, tmp2), text);
	      buff_append(tmp2->wrbuff, buff, len);
	    }
	  tmp2 = tmp2->next;
	}
      tmp = tmp->next;
    }
  buff_append(player->wrbuff, "ok\n", 3);
  my_broadcast_texte_aux(serv, player, text);
}
