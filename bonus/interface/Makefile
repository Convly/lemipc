##
## Makefile for SFML in /home/pazimor/rendu/cpp/cpp_arcade/GRAPHICS/SFML/
##
## Made by hummel_e
## Login   <eddy.hummel@epitech.eu>
##
## Started on  Mon Mar 20 15:44:27 2017 hummel_e
## Last update Sun Apr  2 14:23:23 2017 jsx
##

NAME	=	interface_lemipc

CC 	=	gcc

CFLAGS 	=	-W -Wall -Werror -Wextra -O3
CFLAGS	+=	-I../../srcs/IPC/
CFLAGS	+=	-I../../srcs/instances/
CFLAGS	+=	-I../../srcs/algo/
CFLAGS	+=	-I../../includes/

LFLAGS	+=	-lcsfml-graphics -lcsfml-window
LFLAGS	+=	-lcsfml-system -lcsfml-audio

SRC	=	main.c \

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LFLAGS)
	@printf "\033[0;32minterface compiled successfully <3 !\n\033[0m"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
