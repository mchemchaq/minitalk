# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 21:54:04 by mchemcha          #+#    #+#              #
#    Updated: 2024/04/05 22:35:32 by mchemcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC  = client.c 

SRCSS = server.c util_printf.c printf.c
	
NAMEC = client
NAMES = server 
OBJSS = ${SRCSS:.c=.o}
OBJSC = ${SRCSC:.c=.o}
CC = cc
FLAGS = -Wall -Werror -Wextra 
RM = rm -rf

all: ${NAMEC} ${NAMES}


${NAMES}: ${OBJSS}
	${CC} $(FLAGS) ${OBJSS} -o $(NAMES) 

${NAMEC}: ${OBJSC}
	${CC} $(FLAGS) ${OBJSC} -o $(NAMEC) 

%.o: %.c minitalk.h 
	$(CC) $(FLAGS) -c $< -o $@	

clean:
	$(RM) $(OBJSC) $(OBJSS) 

fclean: clean
	$(RM) $(NAMEC) $(NAMES)

re: fclean all

.PHONY: clean