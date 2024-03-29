# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 14:34:55 by jgrandne          #+#    #+#              #
#    Updated: 2019/11/05 18:57:43 by jgrandne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = libftprintf.a

SRC_PATH = ./src
LIB_PATH = ./libft
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	ft_printf.c \
			ft_parse_conv.c \
			ft_conv_nb.c \
			ft_conv_addr.c \
			ft_flags.c \
			ft_conv_char.c
#ft_apply_flags.c\
			ft_check.c\
			ft_dispatcher.c\
			ft_display_char.c\
			ft_display_numb.c\
			ft_flag_s.c\
			ft_flag_c.c\
			ft_flag_d.c\
			ft_flag_p_undefined.c\
			ft_flag_wu_wo.c\
			ft_flag_u_o.c\
			ft_flag_x.c\
			ft_handler.c\
			ft_printf.c\
			ft_buf.c\
			ft_transform_wchar.c

LIB_NAME = 	ft_atoi.c\
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_putnbru_fd.c \
			ft_itoau.c \
			ft_lgitoa.c \
			ft_isdigit.c
		#	ft_isdigit.c\
			ft_itoa_base.c\
			ft_strlen.c\
			ft_strsub.c\
			ft_wcharlen.c\
			ft_strlwr.c\
			ft_wstrlen.c\
			ft_wstrsub.c

INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)
	@echo "__, ___      __, __, _ _, _ ___ __,"
	@echo "|_   |       |_) |_) | |\ |  |  |_ "
	@echo "|    |       |   | \ | | \|  |  |  "
	@echo "~    ~  ~~~~ ~   ~ ~ ~ ~  ~  ~  ~  "
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJLIB)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf ./obj $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme:
	@norminette $(SRC) $(LIB) $(INC)
	@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m[OK]\033[0m"
