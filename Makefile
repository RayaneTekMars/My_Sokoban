##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME	=	my_sokoban

CC	=	gcc

LIB	=	-lncurses

SRC	=	main.c	\
		src/move.c	\
		src/check.c	\
		src/display.c	\
		src/positions.c	\
		src/read_file.c	\
		src/error.c	\
		lib/my/my_putstr.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_strlen.c	\
		lib/my/my_arrlen.c	\
		lib/my/my_linelen.c	\
		lib/my/my_str_to_word_array.c	\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

FLAGS	=	-W -Wall -Wextra

all:	$(NAME) clean

$(NAME):	$(OBJ)
	@	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIB)

clean:
	@	$(RM) $(OBJ)

fclean:		clean
	@	$(RM) $(NAME)

re:	fclean all

.PHONY : all clean fclean re