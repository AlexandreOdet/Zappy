/*
** instr_server.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Sun Jun 21 01:58:11 2015 Coudray Colin
** Last update Sun Jun 21 02:15:20 2015 Coudray Colin
*/

#include "server.h"

void	sgt(t_server *serv,
	    t_player *client,
	    int *param __attribute__((__unused__)))
{
  char	buff[512];
  int	len;

  len = snprintf(buff, sizeof(buff), "sgt %d\n", serv->time_unit);
  buff_append(client->wrbuff, buff, len);
}

void	seg(t_server *serv __attribute__((__unused__)),
	    t_player *client,
	    int *to_cast)
{
  char	*str;
  char	buff[512];
  int	len;

  str = (char *)to_cast;
  len = snprintf(buff, sizeof(buff), "seg %s\n", str);
  buff_append(client->wrbuff, buff, len);
}

void	smg(t_server *serv __attribute__((__unused__)),
	    t_player *client,
	    int *to_cast)
{
  char	*str;
  char	buff[512];
  int	len;

  str = (char *)to_cast;
  len = snprintf(buff, sizeof(buff), "smg %s\n", str);
  buff_append(client->wrbuff, buff, len);
}

void	suc(t_server *serv __attribute__((__unused__)),
	    t_player *client,
	    int *param __attribute__((__unused__)))
{
  buff_append(client->wrbuff, "suc\n", 4);
}

void	sbp(t_server *serv __attribute__((__unused__)),
	    t_player *client,
	    int *param __attribute__((__unused__)))
{
  buff_append(client->wrbuff, "sbp\n", 4);
}
