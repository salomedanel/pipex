DIRSRC = ./srcs/mandatory/

DIRCINC = ./includes/

DIRLIB = ./libft/

DIRBONUS = ./srcs/bonus/

SRC =	main \
		files \
		free \
		childs \

SRCB =	main_bonus \
		files_bonus \
		free_bonus \
		childs_bonus \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))
SRCSB = $(addprefix ${DIRBONUS}, $(addsuffix .c, ${SRCB}))

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${SRCSB:.c=.o}

NAME = pipex
BONUS_NAME = pipex_bonus
LFT = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	@${CC} ${CFLAGS} -c -I${DIRCINC} -I${DIRLIB} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@cd ${DIRLIB} && ${MAKE}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L./libft -lft
	@echo "✅ pipex created"

${BONUS_NAME}: ${BONUS_OBJS}
	@cd ${DIRLIB} && ${MAKE}
	@${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} -L./libft -lft
	@echo "✅ pipex_bonus created"

all: ${NAME}

clean:
	@${RM} ${OBJS} ${BONUS_OBJS}
	@cd ${DIRLIB} ${DIRBONUS} && ${MAKE} clean
	@echo "🧽 Directory is clean"

fclean:
	@${RM} ${OBJS} ${BONUS_OBJS}
	@${RM} ${NAME} ${BONUS_NAME}
	@cd ${DIRLIB} ${DIRBONUS} && ${MAKE} fclean
	@echo "🧹 Directory is fclean"

re : fclean all

bonus: ${BONUS_NAME}

.PHONY : all clean fclean re bonus
