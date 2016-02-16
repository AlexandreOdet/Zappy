/*
** my_parse_arg.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon May 11 09:33:31 2015 Coudray Colin
** Last update Sun Jul  5 21:21:24 2015 bourrel léo
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

struct	s_flags
{
  char	*lib;
  int	(*func)(t_server*, int, char **);
};

static struct s_flags g_flags[] =
{
  {"-p", &my_parse_p},
  {"-x", &my_parse_x},
  {"-y", &my_parse_y},
  {"-n", &my_parse_n},
  {"-c", &my_parse_c},
  {"-t", &my_parse_t},
  {"-v", &my_parse_v},
  {NULL, NULL}
};

int		my_parse_v(t_server *serv,
			   int ac __attribute__((__unused__)),
			   char **av __attribute__((__unused__)))
{
  static int    count = 0;

  if (count++ > 0)
    {
      fprintf(stderr, "Error: -p : redefinition\n");
      return (-1);
    }
  serv->verbose = 1;
  return (1);
}

int		my_parse_n(t_server *serv, int ac, char **av)
{
  int		i;
  int		retval;

  i = 1;
  retval = 1;
  while (i < ac)
    {
      if (av[i][0] == '-')
	return (retval);
      else
	{
	  if (strcmp(av[i], "GRAPHIC") != 0)
	    {
	      add_team(serv, av[i]);
	      retval += 1;
	    }
	}
      i += 1;
    }
  if (i == 1)
    {
      fprintf(stderr, "Please specify at least a team name\n");
      return (-1);
    }
  return (retval);
}

static void	init_struct_serv(t_server *serv)
{
  bzero(serv, sizeof(t_server));
  serv->port = DEFAULT_PORT;
  serv->width = DEFAULT_WIDTH;
  serv->height = DEFAULT_HEIGHT;
  serv->team_size = DEFAULT_TEAM_SIZE;
  serv->time_unit = DEFAULT_TIME;
}

int		my_parse_arg(t_server *serv, int ac, char **av)
{
  int		i;
  int		j;
  int		tmp;

  init_struct_serv(serv);
  i = 1;
  while (i < ac)
    {
      j = 0;
      while (g_flags[j].lib && strcmp(g_flags[j].lib, av[i]))
	j += 1;
      if (g_flags[j].lib == NULL)
	{
	  fprintf(stderr, "Invalid argument : %s\n", av[i]);
	  return (1);
	}
      else
	if ((tmp = g_flags[j].func(serv, ac - i, av + i)) == -1)
	  return (1);
      i += tmp;
    }
  if (serv->teams == NULL)
    return (1);
  return (0);
}
