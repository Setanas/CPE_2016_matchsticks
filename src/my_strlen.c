/*
** my_strlen.c for bonus in /home/TAN_S/CPool_workshoplib/lib/my
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Fri Oct 21 16:26:00 2016 Sébastien TAN
** Last update Fri Feb 17 18:25:57 2017 Sébastien TAN
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
