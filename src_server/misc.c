/*
** misc.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon May 11 11:39:03 2015 Coudray Colin
** Last update Tue Jun 23 09:29:27 2015 Coudray Colin
*/

#include <stdlib.h>
#include <sys/time.h>

int	my_valid_number(char *number)
{
  int	i;

  i = 0;
  if (number == NULL || number[0] == '\0')
    return (0);
  while (number[i])
    {
      if (number[i] < '0' || number[i] > '9')
	return (0);
      i += 1;
    }
  return (1);
}

char	*strnchr(char *str, char c, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      if (str[i] == c)
	return (&str[i]);
      i += 1;
    }
  return (0);
}

void	add_time(struct timeval *tv, float delay)
{
  tv->tv_sec += (int)delay;
  tv->tv_usec += ((delay - (int)delay) * 1000000);
  if (tv->tv_usec > 1000000)
    {
      tv->tv_sec += (int)(tv->tv_usec / 1000000);
      tv->tv_usec %= 1000000;
    }
}

float	sub_time(struct timeval *a, struct timeval *b)
{
  float	retval;

  retval = (a->tv_sec - b->tv_sec);
  retval += (float)(a->tv_usec - b->tv_usec) / 1000000.0;
  return (retval);
}

int	my_timediff(struct timeval *a, struct timeval *b)
{
  if (a->tv_sec > b->tv_sec)
    return (1);
  else if (a->tv_sec < b->tv_sec)
    return (-1);
  else
    {
      if (a->tv_usec > b->tv_usec)
	return (1);
      if (a->tv_usec < b->tv_usec)
	return (-1);
    }
  return (0);
}
