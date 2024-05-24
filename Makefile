SOURCES = src/instructions/push.c src/instructions/reverse_rotate.c src/instructions/rotate.c src/instructions/swap.c \
	src/main.c src/parse.c src/sort.c src/utils.c
OBJS = $(SOURCES:.c=.o)
LIB_DIR = lib/libft/
LIBFT = $(LIB_DIR)libft.a
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) $(LIBFT) -o $(NAME)

%.o:%.c include/push_swap.h
	cc $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean: clean 
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all
