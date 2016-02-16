/*
** my_bct.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun 19 19:02:42 2015 Coudray Colin
** Last update Mon Jun 22 12:15:50 2015 Coudray Colin
*/

#include <stdlib.h>
#include "server.h"

void	my_bct(t_server *serv, t_player *client, char *str)
{
  int	pos;
  char	*strx;
  char	*stry;
  int	i;

  strx = get_second_word(str);
  stry = get_second_word(strx);
  i = 0;
  while (strx[i] != '\0' && strx[i] != ' ')
    i += 1;
  strx[i] = '\0';
  if (my_valid_number(strx) == 0 || my_valid_number(stry) == 0)
    graphic_instr(serv, client, NULL, SBP);
  else
    {
      pos = COORD(atoi(strx), atoi(stry));
      if (pos > serv->width * serv->height || pos < 0)
	graphic_instr(serv, client, NULL, SBP);
      else
	graphic_instr(serv, client, &pos, BCT);
    }
}
