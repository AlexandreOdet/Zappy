/*
** struct.h for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon May 11 09:03:13 2015 Coudray Colin
** Last update Sat Jun 27 22:05:55 2015 Coudray Colin
*/

#ifndef SERVER_STRUCT_H_
#define SERVER_STRUCT_H_

struct			s_team;
struct			s_server;
typedef void		(*f_event)(struct s_server *, void *);

struct			s_buff
{
  int			size;
  char			*buff;
  int			nb_instr;
};

struct			s_player
{
  int			fd;
  struct timeval	death;
  struct timeval	availability;
  int			inventory[6];
  e_side		side;
  int			pos;
  int			level;
  int			num;
  struct s_team		*team;
  struct s_buff		*wrbuff;
  struct s_buff		*rdbuff;
  struct s_player	*next;
};

struct			s_team
{
  char			*name;
  int			team_size;
  struct s_player	*players;
  struct s_team		*next;
};

struct			s_gen
{
  struct s_gen		*next;
  void			*data;
};

#define			NB_CONTENT (7)

struct			s_case
{
  int			content[NB_CONTENT];
  struct s_gen		*players;
};

typedef struct
{
  int   nb_joueur;
  int   requirement[6];
} t_lvlup;

struct			s_event
{
  struct timeval	when;
  f_event		what;
  void			*data;
  struct s_event	*next;
};

struct			s_egg
{
  int			pos;
  int			num_hen;
  int			num_egg;
  struct s_player	*chick;
  struct s_team		*team;
  struct s_egg		*next;
};

struct			s_server
{
  int			port;
  int			fd;
  int			width;
  int			height;
  int			team_size;
  int			verbose;
  struct timeval	now;
  struct s_case		*map;
  struct s_event	*events;
  struct s_egg		*eggs;
  struct s_team		*teams;
  struct s_player	*graphics;
  struct s_player	*tmp_player;
  int			time_unit;
};

typedef struct s_server	t_server;
typedef struct s_team	t_team;
typedef struct s_player	t_player;
typedef struct s_buff	t_buff;
typedef struct s_case	t_case;
typedef struct s_event	t_event;
typedef struct s_gen	t_gen;
typedef struct s_egg	t_egg;

#endif
