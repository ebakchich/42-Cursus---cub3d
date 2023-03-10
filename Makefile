# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 00:40:29 by ebakchic          #+#    #+#              #
#    Updated: 2023/03/07 23:03:00 by ebakchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c ft_free_db.c ft_run_game.c ft_manage_key.c
NAME    = cub3D
LBFT	= libft/libft.a
CC		= cc -g
CFLAGS  = -Wall -Wextra -Werror #-fsanitize=address
MX		= -lmlx -framework OpenGL -framework Appkit
MAKEC	= make clean
MAKEF	= make fclean
MAKER	= make re
OBJS 	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(MX) ${LBFT} ${OBJS} -o ${NAME}

clean:
	@$(MAKEC) -C libft
	@${RM} ${OBJS}

fclean: clean
	@$(MAKEF) -C libft
	@${RM} ${NAME}

re: fclean all
	@$(MAKER) -C libft

.PHONY: all clean fclean re
