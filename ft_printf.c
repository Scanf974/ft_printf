/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 09:17:00 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 16:44:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	t_format	*fg;
	char		*dst;
	char		*temp;
	char		*same;
	int			len;

	va_start(ap, format);
	i = 0;
	len = 0;
	same = ft_strdup(format);
	if (ft_strlen(same) == 1)
	{
		dst = (char *)malloc(sizeof(char) * 2);
		dst[0] = *same;
		dst[1] = '\0';
		len++;
	}
	else
	{
		dst = ft_strdup("");
		while (*same)
		{
			if (*same == '%')
			{
				i = ft_check_flags(same, &fg, ap);
				temp = ft_putarg(&same[i], ap, fg);
				//dprintf(1, "temp = %s\n", temp);
				if (temp[0] == 0 && fg->conversion != 'd' && fg->conversion != 's')
					len += 1;
				else
					len += ft_strlen(temp);
				same += i;
			}
			else
			{
				temp = (char *)malloc(sizeof(char) * 2);
				temp[0] = *same;
				temp[1] = '\0';
				len++;
			}
			if (ft_strlen(temp))
				dst = ft_strnjoin(dst, temp, len);
			//ft_putstr_c(dst, len);
			//ft_putchar(10);
			same++;
		}
		va_end(ap);
	}
	//ft_putstr("Final = ");
	ft_putstr_c(dst, len);
	return (ft_strlen(dst));
}
