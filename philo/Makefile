CC =		cc
CFLAGS =	-Wall -Wextra -Werror -g -fsanitize=address
NAME =		philo
AR =		ar rcs
SRC =		philo.c \

OBJ =		${SRC:.c=.o}

all:		${NAME}

${NAME}:	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

norm:		all
			norminette ${SRC} push_swap.h
clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean
