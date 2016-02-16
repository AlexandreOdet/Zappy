/*
** main.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon May 11 08:56:44 2015 Coudray Colin
** Last update Fri Jul  3 18:27:13 2015 Coudray Colin
*/

#include <time.h>
#include <signal.h>
#include <sys/select.h>
#include <stdlib.h>
#include "server.h"

int			g_exit = 0;

void			sighandler(int s)
{
  (void)s;
  g_exit = 1;
}

void			main_loop(t_server *serv, fd_set *rdfd, fd_set *wrfd)
{
  struct timeval	tv;

  while (g_exit == 0)
    {
      main_loop_network(serv, rdfd, wrfd, &tv);
      new_player_network(serv, rdfd, wrfd);
      graphic_network(serv, rdfd, wrfd);
      new_player_handler(serv);
      graphic_handler(serv);
      gettimeofday(&serv->now, NULL);
      handle_events(serv);
      player_actions(serv);
    }
}

int			main(int ac, char **av)
{
  t_server		serv;
  fd_set		rdfd;
  fd_set		wrfd;

  srand(time(NULL));
  if (my_parse_arg(&serv, ac, av) == 1)
    {
      fprintf(stderr, "Usage: %s -n name_team1, name_team2 ... \
\n\t\t[-p num_port]\n\t\t[-x width]\n\t\t[-y height]\n\t\t[-t time\
_unit]\n\t\t[-c nb_player_per_team]\n\t\t[-v (enable verbose mode)]\n", *av);
      return (1);
    }
  if (my_init_serv(&serv) == 1)
    return (1);
  if (my_init_map(&serv) == 1)
    return (1);
  if (signal(SIGINT, sighandler) == SIG_ERR)
    return (1);
  main_loop(&serv, &rdfd, &wrfd);
  printf("%s\nExiting\n", KNRM);
  clean_server(&serv);
  return (0);
}
