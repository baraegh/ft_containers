SRC	= main.cpp

NAME = container

FLAGS = -Wall -Wextra -Werror #-std=c++98 -fsanitize=address

all: ${NAME}

${NAME} : ${SRC}
		c++	${FLAGS} ${SRC} -o ${NAME}


clean:
	rm -rf ${NAME}

fclean: clean

re: fclean all