SRCS = srcs/ft_check.c srcs/ft_comp.c srcs/ft_map.c srcs/ft_standard.c srcs/main.c srcs/modif_tab.c srcs/print_map.c

OBJS = $(SRCS:.c=.o)

NAME = bsq

CC = gcc
RM = rm -f

CFLAGS = -I./includes -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

all: 		$(NAME)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bsq
