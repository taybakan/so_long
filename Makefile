NAME 		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit -L./src/mlx -lmlx
LIBFT		= ./src/libft/libft.a 
PRINTF		= ./src/ft_printf/libftprintf.a
GNL			= ./src/gnl/get_next_line.a
MLX			= ./src/mlx/libmlx.a
SRCS		= ./so_long.c ./getmap.c
OBJS		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(SRCS) $(LFLAGS)  -o $(NAME) $(LIBFT) $(PRINTF) $(GNL)

$(LIBFT) :
	@make -C ./src/libft
$(PRINTF) :
	@make -C ./src/ft_printf
$(GNL) :
	@make -C ./src/gnl
clean :
	@rm -rf $(OBJS)

fclean : clean
	@make clean -C ./src/libft
	@make clean -C ./src/ft_printf
	@make clean -C ./src/gnl
	@rm -rf $(NAME)

re : fclean all

.PHONY : all fclean clean re
