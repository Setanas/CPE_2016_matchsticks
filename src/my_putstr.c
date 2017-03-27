/*
** my_putstr.c for bonus in /home/TAN_S/CPool_workshoplib/lib/my
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Fri Oct 21 16:06:35 2016 Sébastien TAN
** Last update Sun Feb 26 16:06:35 2017 Sébastien TAN
*/

#include <unistd.h>
#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	line_error()
{
  write(1, "Line: ", 6);
  return (0);
}
