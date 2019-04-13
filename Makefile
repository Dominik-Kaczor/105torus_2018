##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 105torus.c
##

SRC	=	src/method.c	\
		src/tools_torus.c	\

NAME	=	105torus

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) main.c $(SRC) -lm

clean:
	rm -f $(NAME)

tests_run:
	gcc -o test tests/maintest.c tests/test.c $(SRC) -lm -lcriterion \
	--coverag
	./test

tests_clean:
	rm test
	rm *.gcda
	rm *.gcno

fclean: clean
	rm -f $(NAME)

re:	fclean all
