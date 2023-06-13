# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 12:18:11 by fduque-a          #+#    #+#              #
#    Updated: 2023/05/31 16:03:31 by fduque-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
ARCHIVE = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE) : $(OBJS)
	ar rcs $(ARCHIVE) $^

%.o : %.c 
	$(CC) $(CFLAGS) -I . -c $< -o $@ 

# bonus : 
# 	cd ../checker && make
	
clean :
	rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	rm -f $(NAME)
#	 cd ../checker && make fclean

re : fclean all

.PHONY : all clean fclean re