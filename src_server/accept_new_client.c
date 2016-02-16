/*
** accept_new_client.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Tue May 12 10:53:26 2015 Coudray Colin
** Last update Fri Jun 12 15:41:22 2015 Coudray Colin
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

void			accept_new_client(t_server *serv)
{
  struct sockaddr_in	s_in;
  socklen_t		addrlen;
  t_player		*new_client;

  addrlen = sizeof(struct sockaddr_in);
  if ((new_client = malloc(sizeof(t_player))) == NULL)
    exit(EXIT_FAILURE);
  bzero(new_client, sizeof(t_player));
  new_client->side = rand() % 4;
  new_client->level = 1;
  gettimeofday(&new_client->availability, NULL);
  if ((new_client->wrbuff = malloc(sizeof(t_buff))) == NULL ||
      (new_client->rdbuff = malloc(sizeof(t_buff))) == NULL)
    return ;
  bzero(new_client->wrbuff, sizeof(t_buff));
  bzero(new_client->rdbuff, sizeof(t_buff));
  new_client->fd = accept(serv->fd, (struct sockaddr *)&s_in, &addrlen);
  if (new_client->fd == -1)
    exit(EXIT_FAILURE);
  add_player(&serv->tmp_player, new_client);
  buff_append(new_client->wrbuff, "BIENVENUE\n", strlen("BIENVENUE\n"));
  printf("New client connected\n");
}
