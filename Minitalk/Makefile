# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:29:53 by nkuzminy          #+#    #+#              #
#    Updated: 2023/03/31 09:40:48 by nkuzminy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	GENERAL CONFIG & FLAGS
CC := cc
CFLAGS := -Wall -Wextra -Werror

RM := /bin/rm -f

NAME_SERVER := server
NAME_CLIENT := client

#	MANDATORY PART

SRC_SERVER := server.c minitalk.c
SRC_CLIENT := client.c minitalk.c

#SRC_SERVER_BONUS := server_bonus.c minitalk_bonus.c
#SRC_CLIENT_BONUS := client_bonus.c minitalk_bonus.c

INCLUDES := -I. -Ilibft

LIBFT := ./libft/libft.a
LIBFT_PATH := ./libft

#	RULES

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

# Make libft
$(LIBFT): $(shell make -C $(LIBFT_PATH) -q libft.a)
	make -C $(LIBFT_PATH)

clean:
fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

#bonus: $(LIBFT) fclean
#	$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER)
#	$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT)

#rebonus: fclean bonus

# .PHONY rule in order to avoid relinking
.PHONY: all clean fclean re #bonus #rebonus
