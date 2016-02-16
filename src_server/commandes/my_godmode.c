/*
** my_godmod.c for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Wed Jun 17 16:11:14 2015 Coudray Colin
** Last update Wed Jun 17 16:17:53 2015 Coudray Colin
*/

#include <string.h>
#include "server.h"

void	my_godmode(t_server *serv __attribute__((__unused__)),
		   t_player *player,
		   char *buff __attribute__((__unused__)))
{
  add_time(&player->death, 424242.42);
  buff_append(player->wrbuff,
	      "Vous avez choisi la pilulle bleue...\n",
	      strlen("Vous avez choisi la pilulle bleue...\n"));
}
