/*
** instr_player_action.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Sun Jun 21 01:06:00 2015 Coudray Colin
** Last update Wed Jul  1 11:15:32 2015 Coudray Colin
*/

#include "server.h"

void	pex(t_server *serv __attribute__((__unused__)),
	    t_player *client,
	    int *param)
{
  char	buff[512];
  int	len;

  len = snprintf(buff, sizeof(buff), "pex %d\n", *param);
  buff_append(client->wrbuff, buff, len);
}

void	pbc(t_server *serv, t_player *client, int *param)
{
  (void)serv, (void)client, (void)param;
}

void		pic(t_server *serv, t_player *client, int *to_cast)
{
  t_player	*player;
  t_gen		*tmp;
  char		buff[512];
  int		len;

  player = (t_player *)to_cast;
  tmp = serv->map[player->pos].players;
  len = snprintf(buff, sizeof(buff), "pic %d %d %d %d",
		 player->pos % serv->width, player->pos / serv->height,
		 player->level, player->num);
  while (tmp != NULL)
    {
      if (((t_player *)tmp->data)->num != player->num)
	len += snprintf(&buff[len], sizeof(buff) - len, " %d",
			((t_player *)tmp->data)->num);
      tmp = tmp->next;
    }
  len += snprintf(&buff[len], sizeof(buff) - len, "\n");
  buff_append(client->wrbuff, buff, len);
}

void		pie(t_server *serv, t_player *client, int *param)
{
  (void)serv, (void)client, (void)param;
}
