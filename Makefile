
  
SRCS		=	push_swap.c utils.c 		\
				swap.c push_a.c push_b.c 	\
				rotate.c reverse_rotate.c 	\
				parsing.c sort.c utils2.c \
				small_stack.c ft_split.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -g3 -I./includes

NAME		= 	push_swap

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	rm -rf *.o

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus