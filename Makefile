PROG = pipex

SRCS = pipex.c utils.c
OBJS = $(SRCS:.c=.o)
MAIN = pipex.c

HEADER = pipex.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I. -fsanitize=address

FT_PRINTF_PATH = ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(PROG)

$(PROG): $(OBJS) $(FT_PRINTF) $(LIBFT)
	$(CC)  $(CFLAGS) -o $(PROG) $(OBJS) -L$(FT_PRINTF_PATH) -lftprintf -L$(LIBFT_PATH) -lft

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)
	
clean:
	make -C $(FT_PRINTF_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(FT_PRINTF_PATH) fclean
	make -C $(LIBFT_PATH) fclean
	rm -f $(PROG)

re: fclean all

.PHONY: all clean fclean re