/*
** my_init_serv.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Tue May 12 09:43:20 2015 Coudray Colin
** Last update Tue May 12 15:45:40 2015 Coudray Colin
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "server.h"

int		        my_init_serv(t_server *serv)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;

  if ((pe = getprotobyname("TCP")) == 0)
    return (1);
  if ((serv->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(serv->port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(serv->fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      printf("Error: %s\n", strerror(errno));
      close(serv->fd);
      return (1);
    }
  if (listen(serv->fd, serv->team_size * my_nb_team(serv->teams)) == -1)
    {
      printf("Error: %s\n", strerror(errno));
      close(serv->fd);
      return (1);
    }
  return (0);
}
