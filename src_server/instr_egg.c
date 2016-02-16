/*
** instr_egg.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Sun Jun 21 01:53:40 2015 Coudray Colin
** Last update Thu Jun 25 11:38:33 2015 Coudray Colin
*/

#include "server.h"

void	enw(t_server *serv, t_player *client, int *param)
{
  (void)serv, (void)client, (void)param;
}

void	eht(t_server *serv __attribute__((__unused__)),
	    t_player *client,
	    int *param)
{
  char	buff[512];
  int	len;

  len = snprintf(buff, sizeof(buff), "eht %d\n", *param);
  buff_append(client->wrbuff, buff, len);
}

void	ebo(t_server *serv __attribute__((__unused__)),
	    t_player *client,
	    int *param)
{
  char	buff[512];
  int	len;

  len = snprintf(buff, sizeof(buff), "ebo %d\n", *param);
  buff_append(client->wrbuff, buff, len);
}

void	edi(t_server *serv __attribute__((__unused__)),
	    t_player *client,
	    int *param)
{
  char	buff[512];
  int	len;

  len = snprintf(buff, sizeof(buff), "edi %d\n", *param);
  buff_append(client->wrbuff, buff, len);
}
