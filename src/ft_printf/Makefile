NAME = libftprintf.a
CC = gcc
FLAGS = -c -Wall -Wextra -Werror
RM = rm -rf

SOURCE = ft_printf.c \
		 ft_printf_utils.c

OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY = clean fclean all re
