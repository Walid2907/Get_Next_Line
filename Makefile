# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 11:31:01 by wkerdad           #+#    #+#              #
#    Updated: 2025/11/21 21:54:32 by wkerdad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
CC = cc

CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c
	   
#BONUS =  

OBJFILES = $(SRCS:.c=.o)
#BONUS_OBJ = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJFILES)
	ar rcs $(NAME) $(OBJFILES)

%.o : %.c
	$(CC) -c $< -o  $@

#bonus: $(OBJ) $(BONUS_OBJ)
#	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean : 
	rm -f $(OBJFILES) 

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
