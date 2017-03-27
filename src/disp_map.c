/*
** disp_map.c for bonus in /home/TAN_S/CPE_2016_matchstick/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Wed Feb 15 22:06:14 2017 Sébastien TAN
** Last update Fri Feb 17 18:21:47 2017 Sébastien TAN
*/

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
      incre++;
      beg_pipe--;
      my_putchar('\n');
    }
  put_line_star(end);
}

void	while_disp_map(int map, int end, int beg_pipe)
{
  int	incre;

  incre = 1;
  my_putchar('*');
  while (incre < end-1)
    {
      if (incre == beg_pipe)
	pipe_or_space(&incre, beg_pipe, map);
      else
	my_putchar(' ');
      incre++;
    }
  my_putchar('*');
}

void	put_line_star(int size)
{
  int   incre;

  incre = 0;
  while (incre < size)
    {
      my_putchar('*');
      incre++;
    }
  my_putchar('\n');
}

void	pipe_or_space(int *incre, int beg_pipe, int map)
{
  int	decre;

  decre = 0;
  if (map == 0)
    my_putchar(' ');
  else
    while (*incre < beg_pipe + map)
      {
	my_putchar('|');
	*incre = *incre + 1;
	decre = 1;
      }
  if (decre == 1)
    *incre = *incre - 1;
}

