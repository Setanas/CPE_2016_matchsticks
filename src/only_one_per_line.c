/*
** only_one_per_line.c for matchstick in /home/TAN_S/CPE_2016_matchstick/src
**
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
**
** Started on  Sun Feb 26 20:13:02 2017 Sébastien TAN
** Last update Sun Feb 26 20:20:48 2017 Sébastien TAN
*/

int	only_one_per_line(int *map)
{
  int	incre;
  int	nbr_1;
  int	valid_line;

  valid_line = 0;
  nbr_1 = 0;
  incre = 1;
  while (incre <= map[0])
    {
      if (map[incre] != 0)
	valid_line++;
      if (map[incre] == 1)
	nbr_1++;
      incre++;
    }
  if (valid_line == nbr_1)
    return (1);
  return (0);
}
