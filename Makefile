# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atouati <atouati@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 18:52:47 by atouati           #+#    #+#              #
#    Updated: 2022/03/28 16:08:11 by atouati          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SRCS	= client.c client_util.c

CLIENT_BONUS_SRCS = client_bonus.c client_util.c

SERVER_SRCS = server.c server_util.c 

SERVER_BONUS_SRCS = server_bonus.c server_util.c

CLIENT_OBJS	= ${CLIENT_SRCS:.c=.o}

SERVER_OBJS	= ${SERVER_SRCS:.c=.o}

CLIENT_BONUS_OBJS = ${CLIENT_BONUS_SRCS:.c=.o}

SERVER_BONUS_OBJS = ${SERVER_BONUS_SRCS:.c=.o}

CC	= cc
RM	= rm -f

CLIENT = client

SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

CFLAGS	= -Wall -Werror -Wextra

all: ${CLIENT} ${SERVER} ${CLIENT_BONUS} ${SERVER_BONUS}

${CLIENT}: ${CLIENT_OBJS}
	${CC} ${CFLAGS} ${CLIENT_OBJS} -o ${CLIENT}

${SERVER}: ${SERVER_OBJS}
	${CC} ${CFLAGS} ${SERVER_OBJS} -o ${SERVER}

${CLIENT_BONUS}: ${CLIENT_BONUS_OBJS}
	${CC} ${CFLAGS} ${CLIENT_BONUS_OBJS} -o ${CLIENT_BONUS}

${SERVER_BONUS}: ${SERVER_BONUS_OBJS}
	${CC} ${CFLAGS} ${SERVER_BONUS_OBJS} -o ${SERVER_BONUS}

clean:
	${RM} ${SERVER_OBJS} ${CLIENT_OBJS} ${CLIENT_BONUS_OBJS} ${SERVER_BONUS_OBJS}

fclean: clean
	${RM} ${CLIENT} ${SERVER} ${CLIENT_BONUS} ${SERVER_BONUS}

re: fclean all