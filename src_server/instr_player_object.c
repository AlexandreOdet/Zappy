/*
** instr_player_object.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Sun Jun 21 01:46:10 2015 Coudray Colin
** Last update Thu Jun 25 15:27:30 2015 Coudray Colin
*/

#include "server.h"

void	pfk(t_server *serv __attribute__((__unused__)),
	    t_player *client,
	    int *param)
{
  int	len;
  char	buff[512];

  len = snprintf(buff, sizeof(buff), "pfk %d\n", *param);
  buff_append(client->wrbuff, buff, len);
}

void	pdr(t_server *serv, t_player *client, int *param)
{
  (void)serv, (void)client, (void)param;
}

void	pgt(t_server *serv, t_player *client, int *param)
{
  (void)serv, (void)client, (void)param;
}

void	pdi(t_server *serv __attribute__((__unused__)),
	    t_player *client,
	    int *param)
{
  int	len;
  char	buff[512];

  len = snprintf(buff, sizeof(buff), "pdi %d\n", *param);
  buff_append(client->wrbuff, buff, len);
}
