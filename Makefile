# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 13:45:52 by yabdulha          #+#    #+#              #
#    Updated: 2018/06/23 19:07:15 by yabdulha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_FILES = parser.c split_line.c get_next_line.c build_farm.c error_handler.c \
			check_room.c rooms_list.c count_rooms.c hash.c read_links.c \
			links_list.c solver.c options.c ants_list.c path_list.c \
			send_ants.c main.c print_path.c hash_api.c
SRCS_PATH = srcs/
SRCS = $(addprefix $(SRCS_PATH),$(SRC_FILES))

FLAGS = -Werror -Wextra -Wall

OBJS_PATH = objects/
OBJS_NAME = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))

INCLUDES_PATH = includes/

INCLUDES_NAME = lem_in.h get_next_line.h libft.h
INCLUDES = $(addprefix $(INCLUDES_PATH),$(INCLUDE_NAME))

LIBFT_PATH = libft
LIB = $(addprefix $(LIBFT_PATH)/,libft.a)

FT_PRINTF = libft/ft_printf/libftprintf.a

PRINTF_PATH = libft/ft_printf/
PRINTF_NAME = libftprintf.a
PRINTF_A = $(addprefix $(PRINTF_PATH),$(PRINTF_NAME))
PRINTF_H = $(addprefix $(PRINTF_PATH),includes/ft_printf.h)

.SILENT: all, clean, fclean, re
.PHONY: all, clean, fclean, re

all: libftcomp printfcomp $(NAME)

printfcomp:
	@make -C libft/ft_printf/ all

libftcomp:
	@make -C libft/ all

$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) libft/libft.a $(FT_PRINTF)
	@echo '\033[0;32m'***Compiled***'\033[0m'

$(OBJS): $(SRCS) $(INCLUDES_PATH)
	@echo '\033[0;34m'***Compiling Lem-in***'\033[0m'
	@gcc $(FLAGS) -I$(INCLUDES_PATH) -c $(SRCS)
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@mv $(OBJS_NAME) $(OBJS_PATH)

clean:
	@/bin/rm -rf $(OBJS_PATH)
	@echo '\033[0;31m'***Deleted objects***'\033[0m'
	@make -C libft/ clean
	@make -C libft/ft_printf/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo '\033[0;31m'***Deleted objects and library***'\033[0m'
	@make -C libft/ fclean
	@make -C libft/ft_printf/ fclean

re: fclean all
