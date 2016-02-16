/*
** finish_game.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jul  1 10:51:08 2015 Coudray Colin
** Last update Sun Jul  5 17:35:12 2015 Coudray Colin
*/

#include "server.h"

void	finish_game(t_server *serv __attribute__((__unused__)),
		    void *data __attribute__((__unused__)))
{
  g_exit = 0;
}
