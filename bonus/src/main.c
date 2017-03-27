/*
** main.c for bonus in /home/TAN_S/CPE_2016_matchstick/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Wed Feb 15 11:23:59 2017 Sébastien TAN
** Last update Sat Feb 25 01:27:18 2017 Sébastien TAN
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include <unistd.h>
#include "my.h"

int	main(int ac, char **av)
{
  int	*map;
  int	line;
  int	win_or_lose;

  if (ac != 4)
    return (my_puterror("Too many or not enough arguments\n"));
  if ((check_arg(av[1], av[2])) == 84)
    return (my_puterror("Bad arguments\n"));
  if ((check_arg(av[3], av[2])) == 84)
    return (my_puterror("Bad arguments\n"));
  line = my_getnbr(av[1]);
  if (line < 1 || line > 100)
    return (my_puterror("Bad numbers of lines\n"));
  if ((map = put_map(line)) == NULL)
    return (84);
  if ((my_getnbr(av[3])) != 0 && (my_getnbr(av[3])) != 1
	&& (my_getnbr(av[3])) != 2)
    return (my_puterror("Bad level of bot\n"));
  initscr();
  echo();
  disp_map(map);
  win_or_lose = game(map, my_getnbr(av[2]), my_getnbr(av[3]));
  free(map);
  endwin();
  return (win_or_lose);
}

int	my_puterror(char *str)
{
  int	size;

  size = my_strlen(str);
  write(2, str, size);
  return (84);
}

int	*put_map(int line)
{
  int	*int_map;
  int	nbr;
  int	incre;

  if ((int_map = malloc(sizeof(int) * (line + 1))) == NULL)
    return (NULL);
  int_map[0] = line;
  nbr = 1;
  incre = 1;
  while (incre <= line)
    {
      int_map[incre] = nbr;
      incre++;
      nbr = nbr + 2;
    }
  return (int_map);
}
