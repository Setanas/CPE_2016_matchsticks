##
## Makefile for Makefile in /home/TAN_S/CPE_2016_matchstick
##
## Made by Sébastien TAN
## Login   <TAN_S@epitech.net>
##
## Started on  Mon Feb 13 20:59:37 2017 Sébastien TAN
## Last update Mon Feb 27 11:00:42 2017 Sébastien TAN
##

CFLAGS	= -Wall -Wextra

CFLAGS	+= -I include

CC	= gcc

RM	= rm -f

NAME	= matchstick

SRC	= src/main.c			\
	  src/get_next_line.c		\
	  src/my_getnbr.c		\
	  src/my_putchar.c		\
	  src/my_putnbr.c		\
	  src/my_strlen.c		\
	  src/my_putstr.c		\
	  src/game.c			\
	  src/disp_map.c		\
	  src/check.c			\
	  src/random.c			\
	  src/only_one_per_line.c	\
	  src/artificial_intel.c

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
