#include "ft_printf.h"

static void	ft_printf_check(char s, va_list *args, int *len, int *i)
{
	if (s == 's')
		ft_str(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_num(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsign_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexadec(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadec(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_ptr(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_check(str[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
