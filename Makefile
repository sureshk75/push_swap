# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 09:45:57 by schetty           #+#    #+#              #
#    Updated: 2021/12/23 09:24:24 by schetty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Linker
CC			:=	gcc

# Target
NAME		:=	push_swap
NAME_BONUS	:=	checker

# Directories
LIBFTDIR	:=	libft/
LIBFT		:=	libft/libft.a

# Flags, Libraries and Includes
CFLAGS		:=	-Wall -Wextra -Werror

# Functions
DELETE		:=	rm -f

# Source, Objects and Resources
APP1_SOURCE	:=	push_swap.c
APP2_SOURCE	:=	checker.c
COMM_SOURCE	:=	common_check.c		common_move.c		common_solve.c	\
				common_utils.c

# Defauilt Make
all			:	$(LIBFT)
				@ echo Generating $(NAME) executable
				@ $(CC) $(CFLAGS) $(APP1_SOURCE) $(COMM_SOURCE) $(LIBFT) -o $(NAME)

bonus		:	$(LIBFT)
				@ echo Generating $(NAME_BONUS) executable
				@ $(CC) $(CFLAGS) $(APP2_SOURCE) $(COMM_SOURCE) $(LIBFT) -o $(NAME_BONUS)

checker		:	bonus

# Link
$(LIBFT)	:
				@ $(MAKE) bonus -C $(LIBFTDIR) --no-print-directory
				@ $(MAKE) -C $(LIBFTDIR) --no-print-directory

# Clean Objects
clean		:
				@ $(MAKE) clean -C $(LIBFTDIR) --no-print-directory

# Full Clean
fclean		:	
				@ $(MAKE) fclean -C $(LIBFTDIR) --no-print-directory
ifneq ("$(wildcard $(NAME))","")
	@ echo Removing $(NAME) executable
	@ $(DELETE) $(NAME)
else
	@ echo No $(NAME) executable to remove
endif
ifneq ("$(wildcard $(NAME_BONUS))","")
	@ echo Removing $(NAME_BONUS) executable
	@ $(DELETE) $(NAME_BONUS)
else
	@ echo No $(NAME_BONUS) executable to remove
endif

# Recompile
re			:	fclean all

# Non-File Targets
.PHONY		:	all clean fclean re bonus checker