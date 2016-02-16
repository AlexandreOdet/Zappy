/*
** my_lvlup.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun 19 10:28:50 2015 Coudray Colin
** Last update Wed Jul  1 16:49:44 2015 Coudray Colin
*/

#include <stdlib.h>
#include "server.h"

#define INCANTATION_POS	((long)((t_gen *)data)->data)

extern t_lvlup  g_lvltab[];

char		*has_a_team_won(t_server *serv)
{
  t_team	*tmp;
  t_player	*tmp2;
  int		i;
  int		len;
  static char	buff[512];

  tmp = serv->teams;
  len = 0;
  while (tmp != NULL)
    {
      i = 0;
      tmp2 = tmp->players;
      while (tmp2 != NULL)
	{
	  if (tmp2->level == 8)
	    i += 1;
	  tmp2 = tmp2->next;
	}
      if (i >= 6)
	len += snprintf(&buff[len], sizeof(buff) - len,
			len ? ", %s" : "%s", tmp->name);
      tmp = tmp->next;
    }
  return (len == 0 ? NULL : buff);
}

int		get_incantation_result(t_server *serv, void *data)
{
  t_gen		*tmp;
  int		res;

  res = 1;
  if (((t_gen *)data)->next != NULL &&
      nb_same_lvl_player(serv, INCANTATION_POS,
			 ((t_player *)((t_gen *)data)->next->data)->level) >=
      g_lvltab[((t_player *)((t_gen *)data)->next->data)->level
	       - 1].nb_joueur &&
      enough_stone_to_lvlup(serv, (t_player *)((t_gen *)data)->next->data)
      == 1)
    {
      tmp = ((t_gen *)data)->next;
      while (tmp != NULL)
	{
	  if (((t_player *)tmp->data)->pos != INCANTATION_POS)
	    res = 0;
	  tmp = tmp->next;
	}
    }
  else
    res = 0;
  return (res);
}

int		handle_incantation_list(t_server *serv, int res, t_gen *tmp)
{
  int		level;
  t_gen		*to_free;
  int		len;
  char		buff[512];

  level = 0;
  while (tmp != NULL)
    {
      to_free = tmp;
      if (res == 1)
	len = snprintf(buff, sizeof(buff), "niveau actuel : %d\n",
		       ((t_player *)tmp->data)->level + 1);
      else
	len = snprintf(buff, sizeof(buff), "ko\n");
      buff_append(((t_player *)tmp->data)->wrbuff, buff, len);
      if (res == 1)
	{
	  ((t_player *)tmp->data)->level += 1;
	  level = ((t_player *)tmp->data)->level;
	  graphic_instr_all(serv, tmp->data, PLV);
	}
      tmp = tmp->next;
      free(to_free);
    }
  return (level);
}

void		lvlup(t_server *serv, void *data)
{
  t_gen		*tmp;
  int		res;
  int		level;
  char		*winner;

  res = get_incantation_result(serv, data);
  broadcast_incantation_result(serv, INCANTATION_POS, res);
  tmp = ((t_gen *)data)->next;
  if (res == 1)
    consum_stones(serv, ((t_player *)tmp->data)->level, INCANTATION_POS);
  level = handle_incantation_list(serv, res, ((t_gen *)data)->next);
  graphic_instr_all(serv, (int *)((t_gen *)data)->data, BCT);
  if (level == 8 && (winner = has_a_team_won(serv)) != NULL)
    {
      printf("Team %s WON!\n", winner);
      say_bye_to_players(serv);
      graphic_instr_all(serv, (int *)winner, SEG);
      register_event(serv, FINISH_GAME, 0, NULL);
    }
  free(data);
}
