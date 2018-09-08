# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anoroita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 09:58:50 by anoroita          #+#    #+#              #
#    Updated: 2018/09/03 09:59:09 by anoroita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= ft_minishell

FLAGS 		= -Wall -Werror -Wextra

SRC 		= ft_minishell.c ft_environ.c ft_sh_parsing.c ft_build_environ.c ft_sh_start.c \
			ft_builtin_cmd.c ft_control.c ft_bin_files.c ft_cd_cmd.c ft_shell_errors.c
OBJ 		= $(SRC:.c=.o)
INC 		= ft_minishell.h
SRCDIR  	= ./srcs/
OBJDIR  	= ./objs/
INCDIRLIB	= ./libft/includes/
INCDIR		= ./includes/
SRCS    	= $(addprefix $(SRCDIR), $(SRC))
OBJS    	= $(addprefix $(OBJDIR), $(OBJ))
INCS 		= $(addprefix $(INCDIR), $(INC))

all : 		$(NAME)

$(NAME) :
			Make -C libft/
			gcc $(FLAGS) -c $(SRCS) -I $(INCDIR) -I $(INCDIRLIB)
			mkdir -p $(OBJDIR)
			mv $(OBJ) $(OBJDIR)
			gcc $(FLAGS) -o $(NAME) $(OBJS) -L./libft -lft
			echo "$(NAME) has been created !"

.PHONY: 	clean fclean re

clean : 
			Make -C ./libft/ clean
			rm -rf $(OBJS)
			rm -rf $(OBJDIR)
			echo "objects files has been removed !"

fclean :	clean
			Make -C ./libft/ fclean
			rm -rf $(NAME)
			echo "$(NAME) has been removed !"

re		: 	fclean all
