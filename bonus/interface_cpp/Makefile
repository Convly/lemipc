##
## Makefile for SFML in /home/pazimor/rendu/cpp/cpp_arcade/GRAPHICS/SFML/
##
## Made by hummel_e
## Login   <eddy.hummel@epitech.eu>
##
## Started on  Mon Mar 20 15:44:27 2017 hummel_e
## Last update Sun Apr  2 14:23:23 2017 jsx
##

NAME	=	interface_lemipc_cpp

CC 	=	g++

CXXFLAGS 	=	-W -Wall -Werror -Wextra
CXXFLAGS	+=	-I../../srcs/IPC/
CXXFLAGS	+=	-I../../srcs/instances/
CXXFLAGS	+=	-I../../srcs/algo/
CXXFLAGS	+=	-I../../includes/

LXXFLAGS	+=	-lsfml-graphics -lsfml-window
LXXFLAGS	+=	-lsfml-system -lsfml-audio

SRC	=	main.cpp \

OBJ	=	$(SRC:.cpp=.o)

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LXXFLAGS)
	@printf "\033[0;32minterface compiled successfully <3 !\n\033[0m"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
