##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for CPE_dante_2018
##

CC				=		gcc

RM				=		rm -f

GEN 			=		generator

SOL				=		solver

all:
				cd $(GEN) && $(MAKE) sweet && cd .. && cd $(SOL) && $(MAKE) sweet

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

sweet:			all clean