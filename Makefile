# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 10:48:21 by hyoh              #+#    #+#              #
#    Updated: 2022/11/10 12:41:55 by hyoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror -fsanitize=address
AR			=	ar -crs
RM			=	rm -f

SRCS_DIR	=	./mandatory
SRCS_BN_DIR	=	./bonus
LIB_DIR		=	./lib
MLX_DIR		=	./minilibx_opengl_20191021
MLX_FLAG	=	-lmlx -framework OpenGL -framework AppKit

SRC			=	so_long.c \
				setting.c \
				valid_path.c \
				player.c \
				utils.c

SRC_BN		=	so_long_bonus.c \
				setting_bonus.c \
				valid_path_bonus.c \
				player_bonus.c \
				enemy_bonus.c \
				utils_bonus.c \

SRCS		=	$(addprefix $(SRCS_DIR)/, $(SRC))
SRCS_BN		=	$(addprefix $(SRCS_BN_DIR)/, $(SRC_BN))
OBJS		=	$(SRCS:.c=.o)
OBJS_BN		=	$(SRCS_BN:.c=.o)

ifdef WITH_BONUS
	OBJECT = $(OBJS_BN)
else
	OBJECT = $(OBJS)
endif

all : $(NAME)

$(NAME): $(OBJECT)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAG) $(OBJECT) -L $(LIB_DIR) -l _ft -L $(MLX_DIR) $(MLX_FLAG) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) $(CFLAG) -c $< -o $@

bonus :
	make WITH_BONUS=1 all

clean :
	make clean -C $(LIB_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS) $(OBJS_BN)

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re