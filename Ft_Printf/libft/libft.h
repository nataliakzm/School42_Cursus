/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:55:35 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/19 15:30:44 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_isascii(int i);
int				ft_isprint(int i);
int				ft_isalpha(int i);
int				ft_isdigit(int i);
int				ft_isalnum(int i);
int				ft_tolower(int i);
int				ft_toupper(int i);

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);

int				ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t n);
int				ft_strncmp(const char *s1, char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t			ft_putchar_fd(char c, int fd);
size_t			ft_putstr_fd(char *s, int fd);
size_t			ft_putnstr_fd(char *s, int n, int fd);
void			ft_putendl_fd(char *s, int fd);
size_t			ft_putnbr_fd(int n, int fd);
size_t			ft_putunbr_fd(unsigned int n, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
