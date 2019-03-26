##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for CPE_dante_2018
##

NAME			=		generator

CC				=		gcc

RM				=		rm -f

SRC             =		main.c                  		\
						map/map_generator.c				\
						path/create_path.c				\

OBJ             =		$(SRC:.c=.o)

CFLAGS			+=		-I "./include" -g3
CFLAGS			+=		-W -Wall -Wextra

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) -o $(NAME)
clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

sweet:			all clean