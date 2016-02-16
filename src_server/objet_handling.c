/*
** objet_handling.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Sun Jun 14 21:22:02 2015 Coudray Colin
** Last update Wed Jul  1 11:24:29 2015 Coudray Colin
*/

#include <string.h>
#include "server.h"

struct		s_map
{
  char		*lib;
  e_stones	num;
};

static struct s_map	g_mtab[] =
  {
    {"linemate", LINEMATE},
    {"deraumere", DERAUMERE},
    {"sibur", SIBUR},
    {"mendiane", MENDIANE},
    {"phiras", PHIRAS},
    {"thystame", THYSTAME},
    {"nourriture", FOOD},
  };

int		is_object(char *str)
{
  unsigned int	i;

  i = 0;
  while (i < sizeof(g_mtab) / sizeof(struct s_map) &&
	 strcmp(g_mtab[i].lib, str) != 0)
    i += 1;
  if (i == sizeof(g_mtab) / sizeof(struct s_map))
    return (-1);
  return (g_mtab[i].num);
}
