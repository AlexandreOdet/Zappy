/*
** instr_map.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Sat Jun 20 23:53:52 2015 Coudray Colin
** Last update Sun Jul  5 17:38:31 2015 Coudray Colin
*/

#include "server.h"

void	msz(t_server *serv,
	    t_player *client,
	    int *param __attribute__((__unused__)))
{
  char	buff[512];
  int	len;

  len = snprintf(buff, sizeof(buff), "msz %d %d\n", serv->width, serv->height);
  buff_append(client->wrbuff, buff, len);
}

void	bct(t_server *serv, t_player *client, int *param)
{
  int	len;
  char	buff[512];

  if (param != NULL && (long)param > 0x1000)
    {
      len = snprintf(buff, sizeof(buff), "bct %d %d %d %d %d %d %d %d %d\n",
		     *param % serv->width, *param / serv->width,
		     serv->map[*param].content[FOOD],
		     serv->map[*param].content[LINEMATE],
		     serv->map[*param].content[DERAUMERE],
		     serv->map[*param].content[SIBUR],
		     serv->map[*param].content[MENDIANE],
		     serv->map[*param].content[PHIRAS],
		     serv->map[*param].content[THYSTAME]
		     );
      buff_append(client->wrbuff, buff, len);
    }
}
