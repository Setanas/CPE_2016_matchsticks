/*
** artificial_intel.c for bonus in /home/TAN_S/CPE_2016_matchstick/bonus/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Fri Feb 17 18:21:05 2017 Sébastien TAN
** Last update Sat Feb 25 01:28:20 2017 Sébastien TAN
*/

#include <ncurses/curses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "my.h"

int	play_of_ai_or_not(int *map, int max_sticks, int bot)
{
  disp_map(map);
  if (check_stick(map) == 0)
    {
      printw("You lost, too bad\n");
      refresh();
      sleep(5);
      return (2);
    }
  printw("\nAI's turn...\n");
  if (bot == 2 || bot == 0)
    play_of_ai_cheat(map, max_sticks);
  else
    play_of_ai(map, max_sticks);
  disp_map(map);
  if (check_stick(map) == 0 && bot == 2)
    cheat_bot(map);
  if (check_stick(map) == 0 && bot == 0)
    {
      printw("I lost... snif... but I'll get you next time!!\n");
      refresh();
      sleep(5);
      return (1);
    }
  return (0);
}

void	play_of_ai_cheat(int *map, int max_sticks)
{
  if ((last_line_or_not_cheat(map)) == 0)
    not_last_line_cheat(map, max_sticks);
  else
    last_line_cheat(map, max_sticks);
}

void	last_line_cheat(int *map, int max_sticks)
{
  int	line;
  int	match;

  line = 1;
  while (map[line] == 0)
    line++;
  match = rand() % max_sticks + 1;
  if (map[line] != 1)
    while (match >= map[line])
	match = rand() % max_sticks + 1;
  else
    match = 1;
  map[line] = map[line] - match;
  write_removed_ai(line, match);
}

void	not_last_line_cheat(int *map, int max_sticks)
{
  int	line;
  int	match;

  line = rand() % map[0] + 1;
  match = 0;
  while (map[line] == 0)
      line = rand() % map[0] + 1;
  match = rand() % max_sticks + 1;
  while (match > map[line])
      match = rand() % max_sticks + 1;
  map[line] = map[line] - match;
  write_removed_ai(line, match);
}

int	last_line_or_not_cheat(int *map)
{
  int	line;
  int	incre;

  incre = 0;
  line = 0;
  while (incre <= map[0])
    {
      if (map[incre] == 0)
	line++;
      incre++;
    }
  if (line == map[0] - 1)
    return (1);
  return (0);
}
