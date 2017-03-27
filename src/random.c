/*
** random.c for matchstick in /home/TAN_S/CPE_2016_matchstick/new_IA/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Fri Feb 24 18:49:10 2017 Sébastien TAN
** Last update Sun Feb 26 20:20:38 2017 Sébastien TAN
*/

#include <stdlib.h>
#include "my.h"

void	no_to_random(int *map, int max_sticks, int xor)
{
  int	incre;
  int	quit;

  incre = 1;
  quit = 0;
  while (incre <= map[0] && quit == 0)
    {
      if ((map[incre] ^ xor) < map[incre] && xor <= map[incre])
	{
	  quit = 1;
	  incre = incre - 1;
	}
      incre++;
    }
  if (quit != 1)
    go_to_rand(map, max_sticks);
  else
    {
      if ((xor - 1) == 0)
	xor = 2;
      map[incre] = map[incre] - (xor - 1);
      write_removed_ai(incre, (xor - 1));
    }
}

void	go_to_rand(int *map, int max_sticks)
{
  int	line;
  int	match;
  int	xor;

  line = rand() % map[0] + 1;
  match = 0;
  xor = 0;
  while (xor == 0)
    {
      while (map[line] == 0)
	line = rand() % map[0] + 1;
      match = rand() % max_sticks + 1;
      while (match > map[line])
	match = rand() % max_sticks + 1;
      xor = xor_null(map, line, match);
    }
  map[line] = map[line] - match;
  write_removed_ai(line, match);
}

int	xor_null(int *map, int line, int match)
{
  int	incre;
  int	xor;

  incre = 2;
  map[line] = map[line] - match;
  xor = map[1];
  while (incre <= map[0])
    {
      xor = xor ^ map[incre];
      incre++;
    }
  map[line] = map[line] + match;
  if (xor == 0 && (only_one_per_line(map)) != 1)
    return (0);
  return (1);
}

void	last_two_line(int *map, int max_sticks)
{
  int	line_1;
  int	line_2;

  line_1 = 1;
  while (line_1 < map[0] && map[line_1] == 0)
    line_1++;
  line_2 = line_1 + 1;
  while (line_2 < map[0] && map[line_2] == 0)
    line_2++;
  if (map[line_1] == 1)
    finish_him(map, max_sticks, line_2);
  else if (map[line_2] == 1)
    finish_him(map, max_sticks, line_1);
  else if (map[line_1] != 2)
    {
      map[line_1] = map[line_1] - 1;
      write_removed_ai(line_1, 1);
    }
  else
    {
      map[line_2] = map[line_2] - 1;
      write_removed_ai(line_2, 1);
    }
}

void	finish_him(int *map, int max_sticks, int line)
{
  int	match;

  if (map[line] <= max_sticks)
    match = map[line];
  else
    match = map[line] % (max_sticks + 1);
  map[line] = map[line] - match;
  write_removed_ai(line, match);
}
