/*
** main.c for bonus in /home/TAN_S/CPE_2016_matchstick/src
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Wed Feb 15 11:23:59 2017 Sébastien TAN
** Last update Fri Feb 24 01:37:53 2017 Sébastien TAN
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "my.h"

int	main(int ac, char **av)
{
  int	*map;
  int	line;
  int	win_or_lose;

  if (ac != 3)
    return (my_puterror("Too many or not enough arguments\n"));
  if ((check_arg(av[1], av[2])) == 84)
    return (my_puterror("Bad arguments\n"));
  line = my_getnbr(av[1]);
  if (line < 1 || line > 100)
    return (my_puterror("Bad numbers of lines\n"));
  if ((map = put_map(line)) == NULL)
    return (84);
  srand(time(NULL));
  disp_map(map);
  win_or_lose = game(map, my_getnbr(av[2]));
  free(map);
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
