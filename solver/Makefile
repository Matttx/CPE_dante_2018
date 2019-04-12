##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for CPE_dante_2018
##

NAME			=		solver

CC				=		gcc

RM				=		rm -f

SRC             =		main.c          			\
						get_maze/get_maze.c			\
						get_maze/count.c			\
						solve_maze.c				\

OBJ             =		$(SRC:.c=.o)

CFLAGS			+=		-I "./include/"
CFLAGS			+=		-W -Wall -Wextra -g3

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) -o $(NAME)
clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

sweet:			all clean