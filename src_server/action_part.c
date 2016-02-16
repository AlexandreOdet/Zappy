/*
** action_part.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun  5 13:19:46 2015 Coudray Colin
** Last update Wed Jul  1 11:10:48 2015 Coudray Colin
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"

void		new_player_handler(t_server *serv)
{
  char		*buff;
  t_player	*tmp;
  int		val;

  tmp = serv->tmp_player;
  while (tmp != NULL)
    {
      if ((buff = get_instruction(tmp)) != NULL)
        {
	  if (strcmp(buff, "GRAPHIC") == 0)
	    add_player_to_graphic(serv, tmp);
	  else
	    {
	      if ((val = add_player_to_team(serv, tmp, buff)) == 0)
		place_player(serv, tmp);
	    }
	  if (serv->verbose)
	    printf("%sRead from %d : %s\n", KMAG, tmp->num, buff);
          free(buff);
	  tmp = NULL;
        }
      else
        tmp = tmp->next;
    }
}

void		graphic_handler(t_server *serv)
{
  char		*buff;
  t_player	*tmp;

  tmp = serv->graphics;
  while (tmp != NULL)
    {
      if ((buff = get_instruction(tmp)) != NULL)
	{
	  graphic_cmd(serv, tmp, buff);
	  if (serv->verbose)
	    printf("%sRead from %d : %s\n", KMAG, tmp->num, buff);
	  free(buff);
	}
      tmp = tmp->next;
    }
}

static void	player_actions_aux(t_server *serv, t_player *player, char *buff)
{
  do_action(serv, player, buff);
  if (serv->verbose)
    printf("%sRead from %d : %s\n", KMAG, player->num, buff);
  free(buff);
}

void		player_actions(t_server *serv)
{
  t_team	*tmp;
  t_player	*tmp2;
  char		*buff;

  tmp = serv->teams;
  while (tmp != NULL)
    {
      tmp2 = tmp->players;
      while (tmp2 != NULL)
        {
	  if (my_timediff(&serv->now, &tmp2->death) == 1)
	    player_death(serv, tmp2);
	  else
	    {
	      if (my_timediff(&serv->now, &tmp2->availability) != -1 &&
		  (buff = get_instruction(tmp2)) != NULL)
		player_actions_aux(serv, tmp2, buff);
	    }
	  tmp2 = tmp2->next;
        }
      tmp = tmp->next;
    }
}
