CC =		cc
CFLAGS =	-Wall -Wextra -Werror -g -fsanitize=address
NAME =		test
AR =		ar rcs
SRC =		test.c \

OBJ =		${SRC:.c=.o}

all:		${NAME}

${NAME}:	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

norm:		all
			norminette ${SRC} test.h
clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean
