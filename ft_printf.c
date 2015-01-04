/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 09:17:00 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/31 01:23:59 by bsautron         ###   ########.fr       */
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

	va_start(ap, format);
	i = 0;
	same = ft_strdup(format);
	if (ft_strlen(same) == 1)
	{
		dst = (char *)malloc(sizeof(char) * 2);
		dst[0] = *same;
		dst[1] = '\0';
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
				same += i;
			}
			else
			{
				temp = (char *)malloc(sizeof(char) * 2);
				temp[0] = *same;
				temp[1] = '\0';
			}
			dst = ft_strjoin(dst, temp);
			same++;
		}
		va_end(ap);
	}
	ft_putstr(dst);
	return (ft_strlen(dst));
}
