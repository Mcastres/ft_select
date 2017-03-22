# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 15:00:00 by mcastres          #+#    #+#              #
#    Updated: 2017/03/22 09:55:43 by mcastres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

#Name
NAME = ft_select

#Flag
FLAGS = -Wall -Wextra -Werror

#SRCS
SRCS =	srcs/ft_select.c \
		srcs/ft_init_term.c \
		srcs/ft_ltos.c \
		srcs/ft_read_commande.c \
		srcs/main.c \
		srcs/ft_arrow_key.c \
		srcs/ft_print_all.c \
		srcs/ft_putc.c \
		srcs/ft_valide_select.c \
		srcs/signal.c \

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
