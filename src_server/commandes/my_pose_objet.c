/*
** my_pose_objet.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun  3 11:06:09 2015 Coudray Colin
** Last update Thu Jun 25 11:37:16 2015 Coudray Colin
*/

#include "server.h"

static void	my_pose_objet_aux(t_server *serv, t_player *player, int numobj)
{
  t_player	*tmp;
  int		len;
  char		buff[512];

  len = snprintf(buff, sizeof(buff), "pdr %d %d\n", player->num, numobj);
  tmp = serv->graphics;
  while (tmp != NULL)
    {
      buff_append(tmp->wrbuff, buff, len);
      tmp = tmp->next;
    }
  graphic_instr_all(serv, (int *)player, PIN);
  graphic_instr_all(serv, &player->pos, BCT);
}

void		my_pose_objet(t_server *serv, t_player *player, char *buff)
{
  int		numobj;

  numobj = is_object(get_second_word(buff));
  if (numobj != -1 && player->inventory[numobj] > 0)
    {
      serv->map[player->pos].content[numobj] += 1;
      if (numobj == FOOD)
        add_time(&player->death, -(DELAY_FOOD / serv->time_unit));
      else
        player->inventory[numobj] -= 1;
      buff_append(player->wrbuff, "ok\n", 3);
      my_pose_objet_aux(serv, player, numobj);
    }
  else
    buff_append(player->wrbuff, "ko\n", 3);
}
