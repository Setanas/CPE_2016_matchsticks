/*
** my_putchar.c for bonus in /home/TAN_S/CPool_Day07/test_task02
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Tue Oct 11 16:11:28 2016 Sébastien TAN
** Last update Fri Feb 17 18:25:13 2017 Sébastien TAN
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
