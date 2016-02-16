/*
** my_incantation.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun  3 11:06:09 2015 Coudray Colin
** Last update Wed Jul  1 11:26:41 2015 Coudray Colin
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"

t_lvlup g_lvltab[] =
  {
    {1, {1, 0, 0, 0, 0, 0}},
    {2, {1, 1, 1, 0, 0, 0}},
    {2, {2, 0, 1, 0, 2, 0}},
    {4, {1, 1, 2, 0, 1, 0}},
    {4, {1, 2, 1, 3, 0, 0}},
    {6, {1, 2, 3, 0, 1, 0}},
    {6, {2, 2, 2, 2, 2, 1}},
  };

int	nb_same_lvl_player(t_server *serv, int pos, int level)
{
  int	i;
  t_gen	*tmp;

  i = 0;
  tmp = serv->map[pos].players;
  while (tmp != NULL)
    {
      if (((t_player *)tmp->data)->level == level)
	i += 1;
      tmp = tmp->next;
    }
  return (i);
}

/*
** /!\ Sets the list's first elem's data to pos of the incantation /!\
*/
t_gen	*build_player_list(t_case *c, int level)
{
  t_gen	*retval;
  t_gen	*new;
  t_gen	*next;
  t_gen	*tmp;

  tmp = c->players;
  retval = NULL;
  if ((retval = malloc(sizeof(t_gen))) == NULL)
    return (NULL);
  retval->data = (void *)((long)((t_player *)c->players->data)->pos);
  next = retval;
  while (tmp != NULL)
    {
      if (((t_player *)tmp->data)->level == level)
	{
	  if ((new = malloc(sizeof(t_gen))) == NULL)
	    return (NULL);
	  new->data = tmp->data;
	  new->next = NULL;
	  next->next = new;
	  next = new;
	}
      tmp = tmp->next;
    }
  return (retval);
}

int	enough_stone_to_lvlup(t_server *serv, t_player *player)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      if (serv->map[player->pos].content[i] <
	  g_lvltab[player->level - 1].requirement[i])
	return (0);
      i += 1;
    }
  return (1);
}

void	my_incantation(t_server *serv,
		       t_player *player,
		       char *useless __attribute__((__unused__)))
{
  t_gen	*list_incant;
  char  buff[512];
  int   len;

  if (nb_same_lvl_player(serv, player->pos, player->level) >=
      g_lvltab[player->level - 1].nb_joueur &&
      enough_stone_to_lvlup(serv, player))
    {
      len = snprintf(buff, sizeof(buff), "elevation en cours\n");
      buff_append(player->wrbuff, buff, len);
      list_incant = build_player_list(&serv->map[player->pos], player->level);
      register_event(serv, LVLUP, 300.0 / serv->time_unit,
		     (void *)list_incant);
      graphic_instr_all(serv, (int *)player, PIC);
    }
  else
    buff_append(player->wrbuff, "ko\n", 3);
}
