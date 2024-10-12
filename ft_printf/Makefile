NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

AR = ar crs

SRCS = 	ft_printf.c check_format.c ft_putchar.c ft_putstr.c \
		ft_putnbr.c ft_puthex.c ft_put_u.c ft_putptr.c ft_puthex_extra.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re