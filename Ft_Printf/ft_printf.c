#include "libft.h"
#include <stdio.h>

t_print	*ft_init_tab(t_print *table)
{
	table -> len = 0;
	table -> width = 0;
	table -> dwidth = 0;
	table -> precision = 0;
	table -> zero = 0;
	table -> point = 0;
	table -> sign = 0;
	table -> total_len = 0;
	table -> is_zero = 0;
	table -> dash = 0;
	table -> percentage = 0;
	table -> space = 0;
	return (table);
}

int	ft_printf(const char *string, ...)
{
	t_print	*table;
	//va_list	args;
	//char	*name;
	//unsigned int	days;
	unsigned int	retval;

	table = (t_print *)malloc(sizeof(t_print));
	if (!tab || !string)
		return (-1);
	ft_init_tab(table);
	va_start(table->args, string);
	retval = 0;
	while (*string)
	{
		if (*string != '%')
			retval += write(1, string, 1);
		else
		{
			string = ft_check_str(table, string + 1);
			retval += table ->tl;
			ft_init_tab(table);
		}
		string++;
	}
	//name = va_arg(args, char *);
	//days = va_arg(args, int);
	//ft_printf(name);
	//ft_printf(days);
	va_end(table->args);
	free(table)
	return (retval);	
}


