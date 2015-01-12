#include "ft_printf.h"

void	ft_putstr_c(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}
