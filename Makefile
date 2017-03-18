# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 15:00:00 by mcastres          #+#    #+#              #
#    Updated: 2017/03/18 16:53:09 by mcastres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME = ft_select

#Flag
FLAGS = -Wall -Wextra -Werror

#SRCS
SRCS =	srcs/main.c \
		srcs/out.c  \
		srcs/term.c \
		srcs/list.c \
		srcs/display.c \

#INCLUDES
INCLUDES = includes/ft_select.h


# COLORS
C_NO =	"\033[00m"
C_OK =	"\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

# DBG MESSAGE
SUCCESS	= $(C_GOOD)SUCCESS$(C_NO)
OK = $(C_OK)OK$(C_NO)

#Objects
OBJ=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling" [$(NAME)] "..."
	@make -C libft/
	@make -C libft/ft_printf/
	@gcc -I includes libft/libft.a libft/ft_printf/srcs/libftprintf.a -o $(NAME) $(SRCS) -lreadline -ltermcap -g
	@clear
	@echo "Compiling" [$(NAME)] $(SUCCESS)

%.o: %.c
	@gcc -I includes -o $@ -c $< $(FLAGS)

clean:
	@rm -rf $(OBJ) $(OBJ_MAIN)
	@make clean -C libft/
	@make clean -C libft/ft_printf/
	@echo "Cleaning" [$(NAME)] "..." $(OK)

fclean: clean
	@rm -f $(NAME) $(LIB)
	@make fclean -C libft/
	@make fclean -C libft/ft_printf/
	@echo "Delete" [$(NAME)] $(OK)

re: fclean all

.PHONY: all clean fclean re
