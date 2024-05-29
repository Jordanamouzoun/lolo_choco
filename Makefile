##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## a makefile to compile
##

SRC = src/string.c \
	src/file.c

SRCS =	$(wildcard *.c)

OBJS = $(SRCS:.c=.o)

NAME = 42sh

CC =	gcc

all:
	$(CC) $(SRCS) -o $(NAME) -g3

tests_run:
	gcc -o unit_tests $(SRC) tests/*.c --coverage -lcriterion
	./unit_tests
clean:
	rm -rf *.o *.gcda *.gcno *~ *#

fclean: clean
	rm -rf *.a $(NAME)

re: fclean all
