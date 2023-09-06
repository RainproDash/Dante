##
## EPITECH PROJECT, 2023
## dante
## File description:
## Makefile
##

all	:
		$(MAKE) -C generator
		$(MAKE) -C solver

clean	:
		$(MAKE) -C generator clean
		$(MAKE) -C solver clean

fclean	:
		$(MAKE) -C generator fclean
		$(MAKE) -C solver fclean
		@find . -name "vgcore*" -delete

re	:
		$(MAKE) -C generator re
		$(MAKE) -C solver re
