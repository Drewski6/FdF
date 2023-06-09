# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 14:27:11 by dpentlan          #+#    #+#              #
#    Updated: 2023/06/27 21:04:09 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'

# ***** Sources *****

SRCS = fdf.c \
	   fdf_draw_lines_to_buf_1.c \
	   fdf_draw_lines_to_buf_2.c \
	   fdf_img_utils.c \
	   fdf_la_funcs_1.c \
	   fdf_la_funcs_2.c \
	   fdf_la_funcs_3.c \
	   fdf_map_utils.c \
	   fdf_points_utils_1.c \
	   fdf_points_utils_2.c \
	   fdf_render_line_utils.c \
	   fdf_render_str_utils.c \
	   fdf_render_utils.c \
	   fdf_utils.c \
	   fdf_win_utils_1.c \
	   fdf_win_utils_2.c \

SRCS_DIR = srcs/

# ***** Includes *****

INCS = fdf.h

INCS_DIR = includes/

# ***** Objects *****

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

OBJS_DIR = objs/

# ***** Compile and Archiver *****

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

LIBFT = -Llibft -lft

MLX = -Lmlx -lmlx -lXext -lX11

MATH = -lm

# ***** Build *****

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e -n ${GREEN}
	@make -C libft --silent
	@printf "===== MAKING FDF =====\n"
	@echo -e -n ${NOCOLOR}
	@make -C mlx --silent
	@echo -e -n ${GREEN}
	@printf "===== MAKING MLX =====\n"
	@echo -e -n ${NOCOLOR}
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MATH) $(MLX) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c $(CFLAGS) -I$(INCS_DIR) $< -o $@

clean:
	@make -C libft clean --silent
	@make -C mlx clean --silent
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C libft fclean --silent
	@rm -f $(NAME)
	@rm -f gdb.txt

re: fclean all
