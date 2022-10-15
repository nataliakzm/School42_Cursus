/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:55:35 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/11 17:01:29 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

#define LIBFT_H
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/* **************************** Main part *********************************** */

/* <ctype.h> library */
int ft_isascii(int i);
int ft_isalnum(int i);
int ft_isalpha(int i);
int ft_isdigit(int i);
int ft_isprint(int i);
int ft_toupper(int i);
int ft_tolower(int i);

/* <stdlib.h> library */
int ft_atoi(const char *str);
void *ft_calloc(size_t count, size_t size);

/* <strings.h> library */
void ft_bzero(void *s, size_t n);
void *ft_memset(void *b, int c, size_t len);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memmove(void *s1, const void *s2, size_t n);
void *ft_memcpy(void *dest, const void *stc, size_t n);

/* <string.h> library */
int ft_strlen(const char *str);
int ft_strncmp(const char *s1, char *s2, size_t n);
char *ft_strchr(const char *s, int i);
char *ft_strrchr(const char *s, int i);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
char *ft_strdup(const char *s);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlcat(char *dest, const char *src, size_t size);

/* Second part: Non-standard functions */
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
void ft_striteri(char *s, void (*f)(unsigned int, char *));

char *ft_itoa(int i);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strtrim(char const *s1, char const *set);
char *ft_strjoin(char const *s1, char const *s2);
char **ft_split(char const *str, char c);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* ************************** Bonus part ************************************ */
t_list *ft_lstnew(void *content);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
				  void (*del)(void *));

#endif
