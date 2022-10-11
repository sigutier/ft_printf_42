# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sigutier <sigutier@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 14:53:34 by sigutier          #+#    #+#              #
#    Updated: 2022/08/09 15:46:54 by sigutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= 	libftprintf.a
LIBFT		= 	Libft/
CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra
RM			= 	rm -f
AR			= 	ar rcs

SRC		=		ft_printf.c \
				ft_printf_utils.c \
				ft_print_ptr.c \
				ft_print_unsigned.c \
				ft_print_hex.c

OBJ 		= 	${SRC:.c=.o}

all:			$(NAME)

$(NAME):		$(OBJ)
				make -C $(LIBFT)
				cp Libft/libft.a .
				mv libft.a $(NAME)
				$(AR) $(NAME) $(OBJ)

%.o: %.c
				$(CC) $(CFLAGS) -I $(LIBFT) -c $< -o $@

clean:
				make clean -C $(LIBFT)
				$(RM) -f $(OBJ)

fclean:			clean
				make fclean -C $(LIBFT)
				$(RM) -f $(NAME)

re:				fclean all


.PHONY:			all clean fclean re