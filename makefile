NAME = pipex
SRC = ./ft_pipex.c ./utils.c ./utils_2.c
OBJ = ${SRC:.c=.o}

all: ${OBJ}
	cc ${OBJ} ./get_next_line/gnl.a -o ${NAME} -fsanitize=address

clean:
	rm -f ${OBJ}