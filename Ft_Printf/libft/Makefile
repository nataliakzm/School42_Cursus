NAME	=	libft.a

SRCS	=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c\
		ft_isascii.c	ft_isprint.c	ft_strlen.c\
		ft_memset.c	ft_bzero.c	ft_memcpy.c\
		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c\
		ft_toupper.c	ft_tolower.c	ft_strchr.c\
		ft_strrchr.c	ft_strncmp.c	ft_memchr.c\
		ft_memcmp.c	ft_strnstr.c	ft_atoi.c\
		ft_calloc.c	ft_strdup.c	ft_substr.c\
		ft_strjoin.c	ft_strtrim.c	ft_putchar_fd.c	\
		ft_strmapi.c	ft_putstr_fd.c	ft_striteri.c\
		ft_itoa.c	ft_putnbr_fd.c	ft_putendl_fd.c\
		ft_split.c\

SRCS_B	=	ft_lstnew.c	ft_lstsize.c\

OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) -r $@ $?

bonus: $(OBJS_B)
	$(CC) $(FLAGS) -c $(SRCS) $(SRCS_B)
	ar rcs $(NAME) $(SRCS$_O) $(OBJS_B)

%.o: %.c
	$(CC) -c $(FLAGS) $?

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
