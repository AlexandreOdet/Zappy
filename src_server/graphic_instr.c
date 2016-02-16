/*
** graphic_instr.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Fri Jun 19 19:29:33 2015 Coudray Colin
** Last update Mon Jun 22 10:29:15 2015 Coudray Colin
*/

#include "server.h"

struct s_cmd
{
  char	*lib;
  void	(*func)(t_server *, t_player *, int *);
};

static struct s_cmd g_cmdtab[] =
  {
    {"msz", &msz},
    {"bct", &bct},
    {"tna", &tna},
    {"pnw", &pnw},
    {"ppo", &ppo},
    {"plv", &plv},
    {"pin", &pin},
    {"pex", &pex},
    {"pbc", &pbc},
    {"pic", &pic},
    {"pie", &pie},
    {"pfk", &pfk},
    {"pdr", &pdr},
    {"pgt", &pgt},
    {"pdi", &pdi},
    {"enw", &enw},
    {"eht", &eht},
    {"ebo", &ebo},
    {"edi", &edi},
    {"sgt", &sgt},
    {"seg", &seg},
    {"smg", &smg},
    {"suc", &suc},
    {"sbp", &sbp},
  };

void		graphic_instr(t_server *serv,
			      t_player *client,
			      int *param,
			      e_ginstr instrnum)
{
  g_cmdtab[instrnum].func(serv, client, param);
}

void		graphic_instr_all(t_server *serv, int *param, e_ginstr instrnum)
{
  t_player	*tmp;

  tmp = serv->graphics;
  while (tmp != NULL)
    {
      graphic_instr(serv, tmp, param, instrnum);
      tmp = tmp->next;
    }
}
