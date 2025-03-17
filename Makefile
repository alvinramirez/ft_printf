
NAME = libftprintf.a

SRC =	ft_base.c \
		ft_printf.c \
		ft_pointers.c \
		ft_hexadecimals.c

# Definiendo INCLUDE para incluir archivos de encabezado
INCLUDE = -I .

# Definiendo los archivos objeto
OBJ = $(SRC:.c=.o)

# Opciones de compilación
CC = cc
CFLAGS := -Wall -Wextra -Werror

# Compilar y crear la biblioteca
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Regla para compilar todos los archivos
all: $(NAME)

# Limpiar los archivos objeto
clean:
	rm -f $(OBJ)

# Limpiar los archivos objeto y la biblioteca
fclean: clean
	rm -f $(NAME)

# Reconstruir todo desde cero
re: fclean all

# Compilación individual de archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Declaración de las reglas como "phony" para evitar conflictos con archivos que se llamen igual
.PHONY: all clean fclean re