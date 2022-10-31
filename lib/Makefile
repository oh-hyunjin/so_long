# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 08:33:42 by hyoh              #+#    #+#              #
#    Updated: 2022/10/31 11:52:35 by hyoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	lib_ft.a

CC					=	CC
CFLAG				=	-Wall -Wextra -Werror
RM					=	rm -f
AR					=	ar -crs

INCLUDE_DIR			=	INCLUDE_DIR
LIBFT_DIR			=	src/libft
FT_PRINTF_DIR		=	src/ft_printf
GET_NEXT_LINE_DIR	=	src/get_next_line

LIBFT_SRC			=	ft_isalpha.c \
						ft_isdigit.c \
						ft_isalnum.c \
						ft_isascii.c \
						ft_isprint.c \
						ft_strlen.c \
						ft_memset.c \
						ft_bzero.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_strlcpy.c \
						ft_strlcat.c \
						ft_toupper.c \
						ft_tolower.c \
						ft_strchr.c \
						ft_strrchr.c \
						ft_strncmp.c \
						ft_memcmp.c \
						ft_memchr.c \
						ft_strnstr.c \
						ft_atoi.c \
						ft_calloc.c \
						ft_strdup.c \
						ft_substr.c \
						ft_strjoin.c \
						ft_strtrim.c \
						ft_split.c \
						ft_itoa.c \
						ft_strmapi.c \
						ft_striteri.c \
						ft_putchar_fd.c \
						ft_putstr_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_lstnew.c \
						ft_lstadd_front.c \
						ft_lstsize.c \
						ft_lstlast.c \
						ft_lstadd_back.c \
						ft_lstdelone.c \
						ft_lstclear.c \
						ft_lstiter.c \
						ft_lstmap.c

FT_PRINTF_SRC		=	ft_printf.c \
						option.c \
						type.c \
						put.c \
						getlen.c \
						ft_printf_bonus.c \
						option_bonus.c \
						type_bonus.c \
						put_bonus.c \
						getlen_bonus.c

GET_NEXT_LINE_SRC	=	get_next_line.c \
						get_next_line_utils.c \
						get_next_line_bonus.c \
						get_next_line_utils_bonus.c

all : $(NAME)

$(NAME) : libft ft_printf get_next_line

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@
	$(AR) $(NAME) $@

libft : $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC:.c=.o))
ft_printf : $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRC:.c=.o))
get_next_line : $(addprefix $(GET_NEXT_LINE_DIR)/, $(GET_NEXT_LINE_SRC:.c=.o))

clean :
	$(RM) $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC:.c=.o))
	$(RM) $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRC:.c=.o))
	$(RM) $(addprefix $(GET_NEXT_LINE_DIR)/, $(GET_NEXT_LINE_SRC:.c=.o))

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re libft ft_printf get_next_line