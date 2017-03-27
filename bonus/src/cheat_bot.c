/*
** cheat_bot.c for bonus in /home/TAN_S/CPE_2016_matchstick/bonus/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Fri Feb 17 17:28:59 2017 Sébastien TAN
** Last update Sat Feb 25 01:45:53 2017 Sébastien TAN
*/
#include <ncurses/curses.h>
#include <unistd.h>
#include "my.h"

void	cheat_bot(int *map)
{
  map[1] = 1;
  printw("\nAI used cheat and add 1 match on line 1\n");
  printw("It's super effective\n");
  disp_map(map);
}
