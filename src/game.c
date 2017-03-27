/*
** game.c for bonus in /home/TAN_S/CPE_2016_matchstick
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Wed Feb 15 11:57:45 2017 Sébastien TAN
** Last update Sun Feb 26 16:06:32 2017 Sébastien TAN
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	game(int *map, int max_sticks)
{
  char	*line;
  int	end_game;
  int	error;
  int	win_or_lose;

  end_game = check_stick(map);
  error = 1;
  win_or_lose = 0;
  my_putstr("\nYour turn:\nLine: ");
  while (end_game == 1 && (line = (get_next_line(0))))
    {
      error = check_line(map, line);
      if (error == 1)
	win_or_lose = get_sticks(map, my_getnbr(line), max_sticks);
      free(line);
      end_game = check_stick(map);
      if (error == 0)
	my_putstr("Line: ");
    }
  return (win_or_lose);
}

int	get_sticks(int *map, int line, int max_sticks)
{
  char	*sticks;
  int	end;
  int	error;
  int	win_or_lose;

  end = 0;
  my_putstr("Matches: ");
  while (end == 0 && (sticks = (get_next_line(0))))
    {
      error = check_nbr_sticks(map[line], sticks, max_sticks);
      if (error == 1)
	map[line] = map[line] - my_getnbr(sticks);
      if (error != 0)
	write_removed_player(line, my_getnbr(sticks));
      free(sticks);
      if (error == 0)
	  return (line_error());
      end = 1;
    }
  if (end != 1)
    return (0);
  win_or_lose = play_of_ai_or_not(map, max_sticks);
  if (win_or_lose == 0)
    my_putstr("\nYour turn:\nLine: ");
  return (win_or_lose);
}

void	write_removed_player(int line, int match)
{
  write(1, "Player removed ", 15);
  my_putnbr(match);
  write(1, " match(es) from line ", 21);
  my_putnbr(line);
  my_putchar('\n');
}

void	write_removed_ai(int line, int match)
{
  write(1, "AI removed ", 11);
  my_putnbr(match);
  write(1, " match(es) from line ", 21);
  my_putnbr(line);
  my_putchar('\n');
}
