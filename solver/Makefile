##
## EPITECH PROJECT, 2023
## dante
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.c)

NAME	=	solver

CFLAGS	=	-Wall -Wextra -I./include
CFLAGS	+=	-Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

CC	=	gcc

all:	$(NAME)

$(NAME):	$(SRC)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	@find . -type f -name "vgcore.*" -delete

fclean:	clean
	@find . -type f -name "$(NAME)" -delete

re:	fclean all
