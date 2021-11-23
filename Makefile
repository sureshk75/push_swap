# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 09:45:57 by schetty           #+#    #+#              #
#    Updated: 2021/11/22 12:35:43 by schetty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Linker
CC			:=	gcc

# Target
NAME		:=	pushswap

# Binary Programs
PROG1		:=	push_swap
PROG2		:=	checker

# Directories
OBJDIR		:=	obj/
LIBFTDIR	:=	libft/
LIBFT		:=	libft/libft.a

# Flags, Libraries and Includes
CFLAGS		:=	-Wall -Wextra -Werror

# Functions
ARCHIVE		:=	ar rc
INDEXER		:=	ranlib
DELETE		:=	rm -f
CREATEDIR	:=	mkdir -p
DELETEDIR	:=	rm -Rf

# Colors
RED			:=	"\033[1;31m"
GRN			:=	"\033[1;32m"
YLW			:=	"\033[1;33m"
CLR			:=	"\033[0m"

# Source, Objects and Resources
PROG1_SOURCE:=	push_swap.c		push_swap_utils.c
PROG2_SOURCE:=	checker.c

# Defauilt Make
all			:	outdir $(NAME)

outdir		:
				@ $(CREATEDIR) $(OBJDIR)

bonus		:	outdir $(NAME)

# Link
$(NAME)		:	$(PROG1)	#$(PROG2)
				@ echo $(GRN)$(NAME)$(CLR) Generated Successfully!

$(PROG1)	:	$(LIBFT)
				@ $(CC) $(CFLAGS) $(PROG1_SOURCE) $(LIBFT) -o $(PROG1)

$(PROG2)	:	$(LIBFT)
				@ $(CC) $(CFLAGS) $(PROG2_SOURCE) $(LIBFT) -o $(PROG2)

$(LIBFT)	:
				@ $(MAKE) -C $(LIBFTDIR) --no-print-directory

# Clean Objects
clean		:
ifneq ($(wildcard $(OBJDIR)),)
	@ $(MAKE) clean -C $(LIBFTDIR) --no-print-directory
	@ $(DELETEDIR) $(OBJDIR)
	@ echo $(YLW)$(basename $(NAME))$(CLR) Object Files Deleted!
else
	@ echo No $(RED)$(basename $(NAME))$(CLR)Object Files To Remove..
endif

# Full Clean
fclean		:
ifneq ($(wildcard $(PROG1))$(wildcard $(PROG2)),)
	@ $(MAKE) fclean -C $(LIBFTDIR) --no-print-directory
	@ $(DELETE) $(PROG1) $(PROG2)
	@ $(DELETEDIR) $(OBJDIR)
	@ echo $(YLW)$(basename $(NAME))$(CLR) Binary \& Object Files Deleted!
else
	@ echo No $(RED)$(basename $(NAME))$(CLR) Binary Or Object Files To Removed..
endif

# Recompile
re			:	fclean all

# Non-File Targets
.PHONY		:	all clean fclean re push_swap checker bonus