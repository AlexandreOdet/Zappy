/*
** do_action.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon Jun  1 11:15:57 2015 Coudray Colin
** Last update Thu Jun 25 15:25:19 2015 Coudray Colin
*/

#include <string.h>
#include "server.h"

struct  s_cmd
{
  char  *lib;
  int   delay;
  void  (*func)(t_server *, t_player *, char *);
};

static struct s_cmd g_cmdtab[] =
  {
    {"avance", 7, &my_avance},
    {"droite", 7, &my_droite},
    {"gauche", 7, &my_gauche},
    {"voir", 7, &my_voir},
    {"inventaire", 1, &my_inventaire},
    {"prend", 7, &my_prend_objet},
    {"pose", 7, &my_pose_objet},
    {"expulse", 7, &my_expulse},
    {"broadcast", 7, &my_broadcast_texte},
    {"incantation", 300, &my_incantation},
    {"fork", 42, &my_fork},
    {"connect_nbr", 0, &my_connect_nbr},
    {"godmode", 0, &my_godmode},
    {"coord", 0, &my_coord},
    {NULL, 0, NULL},
  };

int	do_action(t_server *serv, t_player *player, char *buff)
{
  int	i;

  i = 0;
  while (g_cmdtab[i].lib != NULL &&
	 strncmp(g_cmdtab[i].lib, buff, strlen(g_cmdtab[i].lib)) != 0)
    i += 1;
  if (g_cmdtab[i].lib == NULL)
    {
      buff_append(player->wrbuff, "ko\n", 3);
      return (1);
    }
  g_cmdtab[i].func(serv, player, buff);
  gettimeofday(&player->availability, NULL);
  add_time(&player->availability,
	   (float)g_cmdtab[i].delay /(float)serv->time_unit);
  return (0);
}
