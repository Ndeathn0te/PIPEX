# Nombre del ejecutable
NAME = pipex
NAME_BONUS = pipex_bonus

# Directorios
OBJS_DIR = objs
LIBFT_DIR = libft
INCLUDES_DIR = includes

# Archivos fuente
SRCS = pipex.c
SRCS_BONUS = pipex_bonus.c

# Archivos objeto
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)

# Reglas para compilar libft
LIBFT = $(LIBFT_DIR)/libft.a
$(LIBFT):
	make -C $(LIBFT_DIR)

# Regla principal
all: $(LIBFT) $(NAME)

# Compilación del ejecutable principal
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

# Compilación del ejecutable bonus
bonus: $(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft

# Compilación de archivos .o
$(OBJS_DIR)/%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Reglas de limpieza
clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all
