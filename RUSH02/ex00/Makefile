CC = cc
FLAGS = -Wall -Werror -Wextra -g
NAME = rush-02

SRC_DIR = srcs
FILE_DIR = File
SRCS = ${wildcard ${SRC_DIR}/*.c} ${wildcard *.c} ${wildcard ${SRC_DIR}/${FILE_DIR}/*.c}
OBJS = ${patsubst %.c, %.o, ${SRCS}}

all : ${NAME}

${SRC_DIR}%.o : ${SRC_DIR}%.c
	${CC} ${FLAGS} -c $^ -o $@

${NAME} : ${OBJS}
	${CC} ${FLAGS} -o $@ $^

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
