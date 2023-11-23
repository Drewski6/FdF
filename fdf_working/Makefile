# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 14:27:11 by dpentlan          #+#    #+#              #
#    Updated: 2023/11/23 09:19:20 by dpentlan         ###   ########.fr        #
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

DEPENDS		:=	$(patsubst %.c,$(OBJS_DIR)%.d,$(SRCS))
OBJS		:=	$(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))
COMMANDS	:=	$(patsubst %.c,$(OBJS_DIR)%.cc,$(SRCS))

# ***** Build *****

all: $(NAME) compile_commands.json

-include $(DEPENDS)

$(NAME): $(OBJS)
	@echo -e -n ${GREEN}
	@printf "===== MAKING FDF =====\n"
	@echo -e -n ${NOCOLOR}
	@make -C libft --silent
	@echo -e -n ${GREEN}
	@printf "===== MAKING MLX =====\n"
	@echo -e -n ${NOCOLOR}
	@make -C mlx --silent
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MATH) $(MLX) -o $@

COMP_COMMAND = $(CC) -c $(CFLAGS) $(addprefix -I,$(INCS_DIR)) -MMD -MP $< -o $@
CONCAT = awk 'FNR==1 && NR!=1 {print ","}{print}'

$(OBJS_DIR)%.o $(OBJS_DIR)%.cc: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(COMP_COMMAND)
	@printf '{\n\t"directory" : "$(shell pwd)",\n\t"command" : "$(COMP_COMMAND)",\n\t"file" : "$<"\n}' > $(OBJS_DIR)$*.cc

compile_commands.json : $(COMMANDS) Makefile
	@echo "Making compile_commands.json"
	@echo "[" > compile_commands.json
	$(CONCAT) $(COMMANDS) >> compile_commands.json
	@echo "]" >> compile_commands.json

clean:
	@make -C libft clean --silent
	@make -C mlx clean --silent
	@rm -f $(OBJS) $(DEPENDS) $(COMMANDS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C libft fclean --silent
	@rm -f $(NAME) compile_commands.json
	@rm -f gdb.txt

re: fclean all

.PHONY: all clean fclean re bonus
.SUFFIXES:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
