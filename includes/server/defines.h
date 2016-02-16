/*
** defines.h for  in /home/coudra_c/rendu/PSU_2014_zappy
** 
** Made by Coudray Colin
** Login   <coudra_c@epitech.net>
** 
** Started on  Mon May 11 09:04:30 2015 Coudray Colin
** Last update Fri Jul  3 18:26:19 2015 Coudray Colin
*/

#ifndef SERVER_DEFINES_H_
#define SERVER_DEFINES_H_

#define DEFAULT_PORT		4242
#define DEFAULT_WIDTH		25
#define DEFAULT_HEIGHT		25
#define DEFAULT_TIME		100
#define DEFAULT_TEAM_SIZE	6
#define DELAY_FOOD		(126.0)

#define MIN_INT(x, y)		((y) ^ (((x) ^ (y)) & -((x) < (y))))
#define MAX_INT(x, y)		((x) ^ (((x) ^ (y)) & -((x) < (y))))
#define COORD(x, y)		((y) * serv->width + (x))
#define ABS(x)			((x) > 0 ? (x) : -(x))

#define KNRM			"\x1B[0m"
#define KRED			"\x1B[31m"
#define KGRN			"\x1B[32m"
#define KYEL			"\x1B[33m"
#define KBLU			"\x1B[34m"
#define KMAG			"\x1B[35m"
#define KCYN			"\x1B[36m"
#define KWHT			"\x1B[37m"

typedef enum
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    FOOD
  } e_stones;

typedef enum
  {
    UPSIDE,
    LEFTSIDE,
    DOWNSIDE,
    RIGHTSIDE
  } e_side;

typedef enum
  {
    POP_FOOD,
    KILL_PLAYER,
    EGG_HATCHING,
    LVLUP,
    END_FORK,
    FINISH_GAME
  } e_event;

typedef enum
  {
    MSZ,
    BCT,
    TNA,
    PNW,
    PPO,
    PLV,
    PIN,
    PEX,
    PBC,
    PIC,
    PIE,
    PFK,
    PDR,
    PGT,
    PDI,
    ENW,
    EHT,
    EBO,
    EDI,
    SGT,
    SEG,
    SMG,
    SUC,
    SBP
  } e_ginstr;

#endif
