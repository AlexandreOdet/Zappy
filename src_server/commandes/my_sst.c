/*
** my_sst.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun 19 19:02:42 2015 Coudray Colin
** Last update Wed Jul  1 19:05:31 2015 Coudray Colin
*/

#include <stdlib.h>
#include "server.h"

void	my_sst(t_server *serv, t_player *client, char *str)
{
  char	*num;

  num = get_second_word(str);
  if (my_valid_number(num) == 0 || atoi(num) < 1)
    graphic_instr(serv, client, NULL, SBP);
  else
    {
      serv->time_unit = atoi(num);
      graphic_instr(serv, client, NULL, SGT);
    }
}
