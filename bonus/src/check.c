/*
** check.c for bonus in /home/TAN_S/CPE_2016_matchstick
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Wed Feb 15 12:02:26 2017 Sébastien TAN
** Last update Sat Feb 25 01:28:50 2017 Sébastien TAN
*/

#include <ncurses/curses.h>
#include <unistd.h>
#include "my.h"

int	check_arg(char *av1, char *av2)
{
  int	incre;

  incre = 0;
  while (av1[incre] != '\0')
    {
      if (av1[incre] < 48 || av1[incre] > 57)
	return (84);
      incre++;
    }
  incre = 0;
  while (av2[incre] != '\0')
    {
      if (av2[incre] < 48 || av2[incre] > 57)
	return (84);
      incre++;
    }
  return (0);
}

int	check_stick(int *map)
{
  int	incre;

  incre = 1;
  while (incre <= map[0])
    {
      if (map[incre] != 0)
	return (1);
      incre++;
    }
  return (0);
}

int	check_line(int *map, char *line)
{
  int	incre;
  int	nbr_line;
  int	int_line;

  incre = 0;
  if (line[0] == '\0')
    return (er_check_line("Error: invalid input (positive number expected)\n"));
  while (line[incre] != '\0')
    {
      if (line[incre] < 48 || line[incre] > 57)
	return (er_check_line("Error: invalid input (positive number expected)\n"));
      incre++;
    }
  nbr_line = my_getnbr(line);
  if (nbr_line == 0 || nbr_line > map[0])
    return (er_check_line("Error: this line is out of range\n"));
  int_line = my_getnbr(line);
  if (map[int_line] == 0)
    return (er_check_line("Error: there is no more matches on this line\n"));
  return (1);
}

int	er_check_line(char *str)
{
  printw("%s", str);
  refresh();
  return (0);
}

int	check_nbr_sticks(int map, char *nbr_sticks, int max_sticks)
{
  int	incre;
  int	nbr_line;

  incre = 0;
  if (nbr_sticks[0] == '\0')
    return (er_check_line("Error: invalid input (positive number expected)\n"));
  while (nbr_sticks[incre] != '\0')
    {
      if (nbr_sticks[incre] < 48 || nbr_sticks[incre] > 57)
	return (er_check_line("Error: invalid input (positive number expected)\n"));
      incre++;
    }
  nbr_line = my_getnbr(nbr_sticks);
  if (nbr_line == 0)
    return (er_check_line("Error: you have to remove at least one match\n"));
  if (nbr_line > max_sticks)
    {
      printw("Error: you cannot remove more than %d", max_sticks);
      return (er_check_line(" matches per turn\n"));
    }
  if (nbr_line > map)
    return (er_check_line("Error: not enough matches on this line\n"));
  return (1);
}
