# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 16:02:05 by nkuzminy          #+#    #+#              #
#    Updated: 2023/05/05 16:02:06 by nkuzminy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files
NAME = so_long
NAME_BONUS = so_long_bonus
MLX = libmlx.a

SRCS = so_long.c \
	display/*.c \
	parsing/*.c \
	utils/*.c

SRCS_BONUS = bonus/so_long.c \
	bonus/display/*.c \
	bonus/parsing/*.c \
	bonus/utils/*.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Compiler
CC = clang
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11

# Rules
all: $(NAME)
$(NAME): $(OBJS)
	@echo "\033[31;1mCompiling for Linux...\033[0m"
#	@$(MAKE) -C mlx_linux all	
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MLXFLAGS)
	@echo "\033[32m[ ./so_long created ]"

bonus: $(NAME_BONUS)
$(NAME_BONUS): $(OBJS_BONUS)
	@echo "\033[33m[so_long compilation with bonus...]"
#	@$(MAKE) -C mlx_linux all
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(SRCS_BONUS) $(MLXFLAGS)
	@echo "\033[32m[ ./so_long_bonus created ]"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

run: all
	@echo "Please select a map file:"
	@echo "1. Basic map"
	@echo "2. Large map"
	@echo "3. Horizontal map"
	@echo "4. Vertical map"
	@echo "5. Bonus map: Don't forget to run 'make bonus' first"
	@echo "6. Invalid map: lateral wall not configured"
	@echo "7. Invalid map: top or down wall not configured"
	@echo "8. Invalid map: missing PEC"
	@echo "9. Invalid map: not a rectangle"
	@echo "10. Invalid map: unknown char"
	@read -r choice; \
	case $$choice in \
		1) ./$(NAME) maps/map.ber ;; \
		2) ./$(NAME) maps/map_big.ber ;; \
		3) ./$(NAME) maps/map_s1.ber ;; \
		4) ./$(NAME) maps/map_s2.ber ;; \
		5) ./$(NAME_BONUS) maps/map_bonus.ber ;; \
		6) ./$(NAME) maps/map_error_wall1.ber ;; \
		7) ./$(NAME) maps/map_error_wall2.ber ;; \
		8) ./$(NAME) maps/map_error_pec.ber ;; \
		9) ./$(NAME) maps/map_error_ret.ber ;; \
		10) ./$(NAME) maps/map_error_char.ber ;; \
		*) echo "Invalid option. Exiting." ;; \
	esac

clean:
	@rm -f $(OBJ_FILES) $(OBJ_FILES_BONUS)

fclean:
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all
.PHONY: $(NAME) all bonus run clean fclean re