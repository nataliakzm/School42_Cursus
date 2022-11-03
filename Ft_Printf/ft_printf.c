#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*name;
	unsigned int	days;
	unsigned int	count;

	count = 0;
	va_start(args, string);
	name = va_arg(args, char *);
	days = va_arg(args, int);
	ft_printf(name);
	ft_printf(days);
	va_end(args);
	return (0);	
}
