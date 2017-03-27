/*
** my.h for my.h in /home/TAN_S/fonction pratique
** 
** Made by Sébastien TAN
** Login   <TAN_S@epitech.net>
** 
** Started on  Fri Nov 11 12:11:05 2016 Sébastien TAN
** Last update Sun Feb 26 20:26:40 2017 Sébastien TAN
*/

#ifndef READ_SIZE
# define READ_SIZE 1
#endif /* !READ_SIZE */

#ifndef MY_H_
# define MY_H_

typedef struct          s_static
{
  char          buffer[READ_SIZE];
  int           i;
  int           size;
}			t_static;

void			my_putchar(char c);
void			my_putnbr(int nb);
void			my_putstr(char *str);
int			my_strlen(char *str);

      /*my_getnbr*/
int			my_getnbr(char *str);
int			un(int l, char *str, char *nb);
int			deux(int j, int l, char *str, char *nb);
int			trois(int o, char *nb);

      /*get_next_line*/
char                    colgate_2_en_1(t_static *st, int *a, int what_to_do);
char                    *gain_some_line(char *retour);
int                     first_read(char *buffer, char **retour, int *i, int fd);
char                    *reallocation(char *retour, t_static *st,
				      int a, int fd);
char                    *get_next_line(const int fd);

/* main.c */
int	my_puterror(char *str);
int	*put_map(int line);

/* disp_map.c */
void	disp_map(int *map);
void	put_line_star(int size);
void	while_disp_map(int map, int end, int beg_pipe);
void	pipe_or_space(int *incre, int beg_pipe, int map);
void	disp_win_or_lose(int max_sticks);

/* check.c */
int	check_arg(char *av1, char *av2);
int	check_stick(int *map);
int	check_line(int *map, char *line);
int	er_check_line(char *str);
int	check_nbr_sticks(int map, char *nbr_sticks, int max_sticks);

/* game.c */
int	game(int *map, int max_stick, int bot);
int	get_sticks(int *map, int line, int max_sticks, int bot);
void	write_removed_ai(int line, int match);
void	write_removed_player(int line, int match);

/* artificial_intelligence.c */
void    play_of_ai(int *map, int max_sticks);
void    last_line(int *map, int max_sticks);
void    not_last_line(int *map, int max_sticks);
int     last_line_or_not(int *map);

/* artificial_intelligence_cheat.c */
int	play_of_ai_or_not(int *map, int max_sticks, int bot);
void    play_of_ai_cheat(int *map, int max_sticks);
void    last_line_cheat(int *map, int max_sticks);
void    not_last_line_cheat(int *map, int max_sticks);
int     last_line_or_not_cheat(int *map);

/* random.c */
void	no_to_random(int *map, int max_sticks, int xor);
void	go_to_rand(int *map, int max_sticks);
int	xor_null(int *map, int line, int match);
void	last_two_line(int *map, int max_sticks);
void	finish_him(int *map, int max_sticks, int line);

/* cheat_bot.c */
void	cheat_bot(int *map);

int	only_one_per_line(int *map);

#endif /* !MY_H_ */
