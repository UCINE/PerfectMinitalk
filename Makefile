# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lahamoun <lahamoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 02:55:55 by lahamoun          #+#    #+#              #
#    Updated: 2023/01/28 22:16:35 by lahamoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	minitalk
SERVER_NAME	=	server
CLIENT_NAME	=	client
SRVB_NAME = server_bonus
CLTB_NAME = client_bonus
OBJSB= server_bonus.o
OBJCB= client_bonus.o
OBJS:= server.o
OBJC:= client.o
SRC:= utils.o
SRCB:= utils_bonus.o

all:$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):$(SRC) $(OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(OBJS) $(SRC)

$(CLIENT_NAME):$(SRC) $(OBJC)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(OBJC) $(SRC)
	
bonus:$(SRVB_NAME) $(CLTB_NAME)

$(SRVB_NAME):$(SRCB) $(OBJSB)
	$(CC) $(CFLAGS) -o $(SRVB_NAME) $(OBJSB) $(SRCB)

$(CLTB_NAME):$(SRCB) $(OBJCB)
	$(CC) $(CFLAGS) -o $(CLTB_NAME) $(OBJCB) $(SRCB)

clean:
	rm -rf $(OBJS) $(OBJC) $(SRC)
	rm -rf $(OBJSB) $(OBJCB) $(SRCB)

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	rm -rf $(SRVB_NAME) $(CLTB_NAME)
re: fclean all
