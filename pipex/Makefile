CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g

NAME		= pipex

INCS_DIR    = includes
LIBFT_DIR	= libft
PRINTF_DIR	= libft/printf
DIR_O		= file_o

LIBFT_A		= ${LIBFT_DIR}/libft.a
PRINFT_A	= ${PRINTF_DIR}/libftprintf.a

SRCS    	= ft_pipex.c ft_path.c ft_fork.c

SRCS_BONUS	= bonus/pipex_bonus.c bonus/pipex_utils_bonus.c

OBJ			= $(patsubst %.c,file_o/%.o,$(SRCS))
OBJ_BONUS	= $(patsubst %.c,file_o/%.o,$(SRCS_BONUS))

BLUE=\033[0;94m
GREEN=\033[1;92m

all: ${NAME}

$(DIR_O):
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/bonus

file_o/%.o: %.c | $(DIR_O)
	@${CC} ${CFLAGS} -I ${INCS_DIR} -c $< -o $@

${NAME}: ${OBJ}
	@${MAKE} -C ${LIBFT_DIR}
	@${CC} ${CFLAGS} ${OBJ} ${LIBFT_A} ${PRINFT_A} -o ${NAME}
	@echo -e "${GREEN}COMPILATION SUCEED"

bonus: ${OBJ_BONUS}
	@${MAKE} -C ${LIBFT_DIR}
	@${CC} ${CFLAGS} ${OBJ_BONUS} ${LIBFT_A} ${PRINFT_A} -o ${NAME}
	@echo -e "${GREEN}COMPILATION SUCEED"

clean:
	@rm -rf $(DIR_O)
	@${MAKE} -C ${LIBFT_DIR} clean
	@echo -e "${GREEN}ALL IS CLEAN"

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY:	all clean fclean re bonus