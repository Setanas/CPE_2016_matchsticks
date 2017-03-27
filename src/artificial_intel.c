/*
** artificial_intel.c for matchstick in /home/TAN_S/CPE_2016_matchstick/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Thu Feb 16 19:26:51 2017 Sébastien TAN
** Last update Sun Feb 26 20:20:48 2017 Sébastien TAN
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	play_of_ai_or_not(int *map, int max_sticks)
{
  disp_map(map);
  if (check_stick(map) == 0)
    {
      my_putstr("You lost, too bad\n");
      return (2);
    }
  my_putstr("\nAI's turn...\n");
  play_of_ai(map, max_sticks);
  disp_map(map);
  if (check_stick(map) == 0)
    {
      my_putstr("I lost... snif... but I'll get you next time!!\n");
      return (1);
    }
  return (0);
}

void	play_of_ai(int *map, int max_sticks)
{
  int	line_nbr;

  line_nbr = last_line_or_not(map);
  if (line_nbr == 2)
    last_two_line(map, max_sticks);
  else if (line_nbr != 1)
    not_last_line(map, max_sticks);
  else if (line_nbr == 1)
    last_line(map, max_sticks);
}

void	last_line(int *map, int max_sticks)
{
  int	line;
  int	match;
  int	quit;

  quit = 0;
  line = 1;
  while (map[line] == 0)
    line++;
  if (map[line] == 1)
    match = 1;
  else
    while (quit != 1)
	{
	  if ((map[line] - 2 * max_sticks) > 0 || (map[line] - max_sticks) == 1)
	    {
	      match = max_sticks;
	      quit = 1;
	    }
	  max_sticks--;
	}
  map[line] = map[line] - match;
  write_removed_ai(line, match);
}

void	not_last_line(int *map, int max_sticks)
{
  int	incre;
  int	xor;

  incre = 2;
  xor = map[1];
  while (incre <= map[0])
    {
      xor = xor ^ map[incre];
      incre++;
    }
  incre = 1;
  if (xor > max_sticks || xor == 1)
    go_to_rand(map, max_sticks);
  else
    no_to_random(map, max_sticks, xor);
  incre = 2;
  xor = map[1];
  while (incre <= map[0])
    {
      xor = xor ^ map[incre];
      incre++;
    }
}

int	last_line_or_not(int *map)
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
  return (incre - line - 1);
}
