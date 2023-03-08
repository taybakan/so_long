NAME	= get_next_line.a

SRCS	= get_next_line.c get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

$(NAME)	: $(OBJS)
			$(CC) $(CFLAGS) -c $(SRCS)
			ar rc $(NAME) $(OBJS)

all		: $(NAME)

clean	:
			$(RM) $(OBJS)
	
fclean	: clean
			$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
