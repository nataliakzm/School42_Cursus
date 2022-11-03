#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Standard C Libraries

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

// Prototypes

void	ft_putchar_len(char c, int *len);
void	ft_str(char *args, int *len);
void	ft_num(int num, int *len);
void	ft_hexdec(unsigned int x, int *len, char x_or_x);
void	ft_unsign_int(unsigned int u, int *len);
void	ft_ptr(size_t ptr, int *len);

int		ft_printf(const char *str, ...);

#endif
