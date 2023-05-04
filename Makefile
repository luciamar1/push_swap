NAME = push_swap

SRCS = create_list.c movements.c algorithm.c baby_algorithm.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCS:.c=.ob)

LIB = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

$(NAME): $(OBJS)
	@make -C libft
	@rm -rf $(OBJSB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o:%.c
	$(CC) -D BONUS=0 $(CFLAGS) -c $< -o $@
	
%.ob:%.c
	$(CC) -D BONUS=1 $(CFLAGS) -c $< -o $@
	
bonus: $(OBJSB)
	@make -C libft
	@rm -rf $(OBJS)
	$(CC) $(CFLAGS) $(OBJSB) $(LIB) -o $(NAME)

all: $(NAME)

clean:
	@make clean -C libft
	@rm -rf $(OBJS)
	@rm -rf $(OBJSB)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norma bonus