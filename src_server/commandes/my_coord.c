/*
** my_coord.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun 17 16:08:56 2015 Coudray Colin
** Last update Wed Jun 17 16:16:54 2015 Coudray Colin
*/

#include "server.h"

static char	*g_strtab[] =
  {
    "Haut",
    "Gauche",
    "Bas",
    "Droite"
  };

void    my_coord(t_server *serv,
                      t_player *player,
                      char *buff __attribute__((__unused__)))
{
  char	tmp[512];
  int	len;

  len = snprintf(tmp, sizeof(tmp), "coord: (%d/%d), orientation : %s\n",
		 player->pos % serv->width, player->pos / serv->width,
		 g_strtab[player->side]);
  buff_append(player->wrbuff, tmp, len);
}
