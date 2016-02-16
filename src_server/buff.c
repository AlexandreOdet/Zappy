/*
** buff.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon Jun  1 13:46:17 2015 Coudray Colin
** Last update Wed Jul  1 16:15:14 2015 Coudray Colin
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

#define	MAX_INSTRUCTION (10)

void	buff_append(t_buff *buff, char *str, int len)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  if (buff->nb_instr >= 10)
    return ;
  if ((buff->buff = realloc(buff->buff, buff->size + len)) == NULL)
    {
      buff->size = 0;
      buff->nb_instr = 0;
      return ;
    }
  strncpy(&buff->buff[buff->size], str, len);
  buff->size += len;
  while (i < buff->size)
    if (i++ == '\n')
      {
	if (c < MAX_INSTRUCTION)
	  c += 1;
	else
	  buff->size = i;
      }
  buff->nb_instr = c;
}

void	buff_remove(t_buff *buff, int len)
{
  int	i;
  int	c;
  char	*tmp;

  i = 0;
  c = 0;
  if ((tmp = malloc(buff->size - len)) == NULL)
    {
      buff->size = 0;
      buff->nb_instr = 0;
      return ;
    }
  strncpy(tmp, &buff->buff[len], buff->size - len);
  free(buff->buff);
  buff->buff = tmp;
  buff->size -= len;
  while (i < buff->size)
    if (i++ == '\n')
      c += 1;
  buff->nb_instr = c;
}

char	*get_instruction(t_player *player)
{
  char	*ret;
  char	*tmp;
  int	i;

  if (player->rdbuff->size == 0 || player->rdbuff->buff == NULL)
    return (NULL);
  if ((tmp = strnchr(player->rdbuff->buff, '\n',
		     player->rdbuff->size)) == NULL)
    return (NULL);
  i = (tmp - player->rdbuff->buff) + 1;
  if ((ret = malloc(i)) == NULL)
    return (NULL);
  strncpy(ret, player->rdbuff->buff, i);
  ret[i - 1] = '\0';
  buff_remove(player->rdbuff, i);
  return (ret);
}
