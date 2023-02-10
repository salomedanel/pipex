# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:05:40 by sdanel            #+#    #+#              #
#    Updated: 2023/01/11 14:02:15 by sdanel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	get_next_line.c\
	get_next_line_utils.c\
	ft_printf.c\
	ft_printf_utils1.c\
	ft_printf_utils2.c\

OBJS = ${SRCS:.c=.o}

BONUS = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\

BONUS_OBJS = ${BONUS:.c=.o}

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -g
CC = cc
RM = rm -f

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${BONUS_OBJS}
	@ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

all: ${NAME}

clean: 
	@${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	@${RM} ${NAME}

re: @fclean all

bonus:	${OBJS} ${BONUS_OBJS}
	@ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY:	all clean fclean re .c.o bonus
