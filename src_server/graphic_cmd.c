/*
** graphic_cmd.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun 19 14:02:15 2015 Coudray Colin
** Last update Fri Jun 19 19:22:26 2015 Coudray Colin
*/

#include <string.h>
#include "server.h"

struct  s_cmd
{
  char  *lib;
  void  (*func)(t_server *, t_player *, char *);
};

static struct s_cmd g_cmdtab[] =
  {
    {"msz", &my_msz},
    {"bct", &my_bct},
    {"mct", &my_mct},
    {"tna", &my_tna},
    {"ppo", &my_ppo},
    {"plv", &my_plv},
    {"pin", &my_pin},
    {"sgt", &my_sgt},
    {"sst", &my_sst},
    {NULL, NULL}
  };

void	graphic_cmd(t_server *serv, t_player *client, char *buff)
{
  int	i;

  i = 0;
  while (g_cmdtab[i].lib != NULL &&
         strncmp(g_cmdtab[i].lib, buff, strlen(g_cmdtab[i].lib)) != 0)
    i += 1;
  if (g_cmdtab[i].lib == NULL)
    return ;
  g_cmdtab[i].func(serv, client, buff);
}
