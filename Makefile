NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
SRC = ./srcs/utils_error1.c  ./srcs/verifdobl.c ./srcs/array.c ./srcs/windows.c ./srcs/checkerror.c ./srcs/main.c ./srcs/image.c ./srcs/events.c ./srcs/checkplay.c ./srcs/checkplay2.c

all : ${NAME}

OBJS = ${SRC:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	make all bonus -C ./Libft
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) ./Libft/libft.a

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ./so_long
	make fclean -C ./Libft
	

re : fclean all

.PHONY: .c.o all clean fclean bonus re
