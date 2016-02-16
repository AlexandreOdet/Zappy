/*
** my_parse_pxyct.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon May 11 11:12:59 2015 Coudray Colin
** Last update Wed Jun  3 13:02:39 2015 Coudray Colin
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"

int		my_parse_p(t_server *serv, int ac, char **av)
{
  static int	count = 0;

  if (ac == 1 || my_valid_number(av[1]) == 0)
    {
      fprintf(stderr, "Error: -p : need a number\n");
      return (-1);
    }
  if (count++ > 0)
    {
      fprintf(stderr, "Error: -p : redefinition\n");
      return (-1);
    }
  serv->port = atoi(av[1]);
  return (2);
}

int		my_parse_x(t_server *serv, int ac, char **av)
{
  static int	count = 0;

  if (ac == 1 || my_valid_number(av[1]) == 0)
    {
      fprintf(stderr, "Error: -x : need a number\n");
      return (-1);
    }
  if (count++ > 0)
    {
      fprintf(stderr, "Error: -x : redefinition\n");
      return (-1);
    }
  serv->width = atoi(av[1]);
  if (serv->width < 5)
    serv->width = DEFAULT_WIDTH;
  return (2);
}

int		my_parse_y(t_server *serv, int ac, char **av)
{
  static int	count = 0;

  if (ac == 1 || my_valid_number(av[1]) == 0)
    {
      fprintf(stderr, "Error: -y : need a number\n");
      return (-1);
    }
  if (count++ > 0)
    {
      fprintf(stderr, "Error: -y : redefinition\n");
      return (-1);
    }
  serv->height = atoi(av[1]);
  if (serv->height < 5)
    serv->height = DEFAULT_HEIGHT;
  return (2);
}

int		my_parse_c(t_server *serv, int ac, char **av)
{
  static int	count = 0;
  t_team	*tmp;

  tmp = serv->teams;
  if (ac == 1 || my_valid_number(av[1]) == 0)
    {
      fprintf(stderr, "Error: -c : need a number\n");
      return (-1);
    }
  if (count++ > 0)
    {
      fprintf(stderr, "Error: -c : redefinition\n");
      return (-1);
    }
  serv->team_size = atoi(av[1]);
  if (serv->team_size < 1)
    serv->team_size = DEFAULT_TEAM_SIZE;
  if (serv->teams != NULL)
    while (tmp != NULL)
      {
	tmp->team_size = serv->team_size;
	tmp = tmp->next;
      }
  return (2);
}

int		my_parse_t(t_server *serv, int ac, char **av)
{
  static int	count = 0;

  if (ac == 1 || my_valid_number(av[1]) == 0)
    {
      fprintf(stderr, "Error: -t : need a number\n");
      return (-1);
    }
  if (count++ > 0)
    {
      fprintf(stderr, "Error: -t : redefinition\n");
      return (-1);
    }
  serv->time_unit = atoi(av[1]);
  if (serv->time_unit < 1)
    serv->time_unit = DEFAULT_TIME;
  return (2);
}
