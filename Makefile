##
## Makefile for makefile in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/
##
## Made by jsx
## Login   <jean-sebastien.herbaux@epitech.eu>
##
## Started on  Mon Mar 27 10:47:55 2017 jsx
## Last update Sun Apr  2 17:31:16 2017 jsx
##

NAME	=	lemipc

CFLAGS	=	-W -Wall -Werror -Wextra -lm -O3

CFLAGS	+=	-I./includes/
CFLAGS	+=	-I./srcs/IPC/
CFLAGS	+=	-I./srcs/instances/

SRCS	=	srcs/main.c \
		srcs/errors.c \
		srcs/parser.c \
		srcs/init.c \
		srcs/utilsString.c \
		srcs/algo/algo.c \
		srcs/algo/sam.c \
		srcs/algo/lopez.c \
		srcs/algo/baronne.c \
		srcs/algo/alllllaaaamel.c \
		srcs/algo/routes.c \
		srcs/algo/martinez.c \
		srcs/algo/destination.c \
		srcs/IPC/ipcCore.c \
		srcs/IPC/shared_memory.c \
		srcs/IPC/semaphore.c \
		srcs/IPC/msgq.c \
		srcs/instances/player.c \
		srcs/instances/get_stats.c \

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
