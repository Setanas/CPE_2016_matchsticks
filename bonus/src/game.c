/*
** game.c for bonus in /home/TAN_S/CPE_2016_matchstick
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Wed Feb 15 11:57:45 2017 Sébastien TAN
** Last update Sat Feb 25 01:37:00 2017 Sébastien TAN
*/

#include <ncurses/curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	game(int *map, int max_sticks, int bot)
{
  char	line[5];
  int	end_game;
  int	error;
  int	win_or_lose;

  end_game = check_stick(map);
  error = 1;
  printw("\nThe maximum of sticks you can remove is %d", max_sticks);
  printw("\nYour turn:\nLine: ");
  refresh();
  while (end_game == 1)
    {
      getstr(line);
      error = check_line(map, line);
      if (error == 1)
	win_or_lose = get_sticks(map, my_getnbr(line), max_sticks, bot);
      end_game = check_stick(map);
      if (end_game == 1)
	{
	  printw("Line: ");
	  refresh();
	}
    }
  return (win_or_lose);
}

int	get_sticks(int *map, int line, int max_sticks, int bot)
{
  char	sticks[5];
  int	end;
  int	error;
  int	win_or_lose;

  end = 0;
  printw("matches: ");
  refresh();
  while (end == 0)
    {
      getstr(sticks);
      error = check_nbr_sticks(map[line], sticks, max_sticks);
      if (error == 1)
	map[line] = map[line] - my_getnbr(sticks);
      if (error != 0)
	write_removed_player(line, my_getnbr(sticks));
      if (error == 0)
	return (0);
      end = 1;
    }
  win_or_lose = play_of_ai_or_not(map, max_sticks, bot);
  if (win_or_lose == 0)
    disp_win_or_lose(max_sticks);
  return (win_or_lose);
}

void	write_removed_player(int line, int match)
{
  clear();
  printw("Player removed %d match(es) frome line %d\n", match, line);
}

void	write_removed_ai(int line, int match)
{
  printw("AI removed %d match(es) frome line %d\n", match, line);
}
