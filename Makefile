
  
SRCS		=	push_swap.c srcs/utils.c					\
				srcs/swap.c srcs/push_a.c srcs/push_b.c		\
				srcs/rotate.c srcs/reverse_rotate.c			\
				srcs/parsing.c srcs/sort.c srcs/utils2.c	\
				srcs/small_stack.c srcs/ft_split.c			\
				srcs/sort_5.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror

CPPFLAGS	=	-I./includes

NAME		= 	push_swap

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re