/*
** misc2.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon Jun 15 12:42:25 2015 Coudray Colin
** Last update Mon Jun 15 13:30:03 2015 Coudray Colin
*/

#include <stdlib.h>

char	*get_second_word(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0' && str[i] != ' ')
    i += 1;
  if (str[i] == '\0')
    return (&str[i]);
  else
    return (&str[i + 1]);
}
