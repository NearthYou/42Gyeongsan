CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = do-op

SRC_DIR = srcs
INCLUDE_DIR = includes
SRCS = ${wildcard ${SRC_DIR}/*.c}
OBJS = $(SRCS:.c=.o)

all : ${NAME}

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/ft.h
	$(CC) $(FLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY:		all clean fclean re