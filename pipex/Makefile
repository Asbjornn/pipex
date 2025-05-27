CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

NAME	= pipex
INCS    = includes

SRCS    = $(wildcard printf/*.c) $(wildcard *.c)
DIR_O	= file_o

SRC_BONUS =	

BLUE=\033[0;94m
GREEN=\033[1;92m

OBJ    = $(patsubst %.c,file_o/%.o,$(SRCS))
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: ${NAME}

$(DIR_O):
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/printf

file_o/%.o: %.c | $(DIR_O)
	@${CC} ${CFLAGS} -I ${INCS} -c $< -o $@

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME}
	@echo -e "${GREEN}COMPILATION SUCEED"


bonus: ${OBJ} ${OBJ_BONUS}
	@${CC} ${CFLAGS} ${OBJ} ${OBJ_BONUS} -o ${NAME}

clean:
	@rm -rf $(DIR_O)
	@echo -e "${GREEN}ALL IS CLEAN"

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus