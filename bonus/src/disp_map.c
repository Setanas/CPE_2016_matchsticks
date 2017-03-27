/*
** disp_map.c for bonus in /home/TAN_S/CPE_2016_matchstick/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Wed Feb 15 22:06:14 2017 Sébastien TAN
** Last update Sat Feb 25 01:39:06 2017 Sébastien TAN
*/

#include <ncurses/curses.h>
#include "my.h"

void	disp_map(int *map)
{
  int	end;
  int	incre;
  int	beg_pipe;

  end = 1;
  incre = 0;
  while (incre < map[0])
    {
      end = end + 2;
      incre++;
    }
  put_line_star(end);
  incre = 1;
  beg_pipe = end/2;
  while (incre <= map[0])
    {
      while_disp_map(map[incre], end, beg_pipe);
      printw("\t %d\t  %d\n", incre, map[incre]);
      incre++;
      beg_pipe--;
    }
  put_line_star(end);
  refresh();
}

void	while_disp_map(int map, int end, int beg_pipe)
{
  int	incre;

  incre = 1;
  printw("*");
  while (incre < end-1)
    {
      if (incre == beg_pipe)
	pipe_or_space(&incre, beg_pipe, map);
      else
	printw(" ");
      incre++;
    }
  printw("*");
}

void	put_line_star(int size)
{
  int   incre;

  incre = 0;
  while (incre < size)
    {
      printw("*");
      incre++;
    }
  printw("\tline\tmatches\n");
}

void	pipe_or_space(int *incre, int beg_pipe, int map)
{
  int	decre;

  decre = 0;
  if (map == 0)
    printw(" ");
  else
    while (*incre < beg_pipe + map)
      {
	printw("|");
	*incre = *incre + 1;
	decre = 1;
	}
  if (decre == 1)
    *incre = *incre - 1;
}

void	disp_win_or_lose(int max_sticks)
{
  printw("\nThe maximum of sticks you can remove is %d", max_sticks);
  printw("\nYour turn:\n");
  refresh();
}
