/*
** my_ppo.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun 19 19:02:42 2015 Coudray Colin
** Last update Wed Jul  1 11:29:28 2015 Coudray Colin
*/

#include <stdlib.h>
#include "server.h"

void		my_ppo(t_server *serv, t_player *client, char *str)
{
  char		*num;
  t_team	*tmp;
  t_player	*tmp2;

  num = get_second_word(str);
  if (my_valid_number(num) != 0)
    {
      tmp = serv->teams;
      while (tmp != NULL)
	{
	  tmp2 = tmp->players;
	  while (tmp2 != NULL)
	    {
	      if (tmp2->num == atoi(num))
		{
		  graphic_instr(serv, client, (int *)tmp2, PPO);
		  return ;
		}
	      tmp2 = tmp2->next;
	    }
	  tmp = tmp->next;
	}
    }
  graphic_instr(serv, client, NULL, SBP);
}
