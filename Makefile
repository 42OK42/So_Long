# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 14:54:19 by okrahl            #+#    #+#              #
#    Updated: 2023/10/12 17:21:58 by okrahl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

SRCS			=	main.c \
				error_checks.c \
				error_checks_utils_1.c \
				error_checks_utils_2.c \
				helper.c \
				Read_file_and_free.c \
				update_player_position.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_printf.c \
				ft_putchar_fd.c \
				initialise_game.c \
				close_game.c \
				update_player_position_utils.c \
				printcs.c \
				ft_putnbr_fd.c \
				print_math.c \
				print_umath.c \
				error_checks_utils_3.c \
				print_pointer.c \

OBJS			=	${SRCS:.c=.o}

LD_FLAGS		=	-L libft -L mlx

INCL_FLAGS		=	-Lmlx_linux -lmlx -L/usr/local/include/ -Imlx_linux -lXext -lX11 -lm -lz

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes -I libft -I mlx

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

%.o: %.c
	${CC} ${CFLAGS} ${HEAD} -I/usr/local/include -Imlx_linux -O3 -c $< -o $@

$(NAME)			:	${OBJS}
					make -C libft
					${CC} ${OBJS} ${INCL_FLAGS} -o ${NAME}
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all				:	${NAME}

clean			:
					make clean -C libft
					@rm -rf ${OBJS}

fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
