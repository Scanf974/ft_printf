/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfo_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:53:47 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 16:45:02 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_prec_str(char *str, t_format *fg)
{
	char	*dst;

	dst = ft_strdup(str);
	dst[fg->precision] = '\0';
	return (dst);
}

static char	*ft_precision(char *str, t_format *fg)
{
	char	*dst;
	int		prec;

	prec = fg->precision - ft_strlen(str);
	if (prec >= 0 && fg->conversion != 'c' && fg->conversion != 'C'
			&& fg->conversion != 's' && fg->conversion != 'S')
	{
		dst = ft_strnew(prec + 2);
		if (str[0] == '-' || str[0] == '+')
		{

			prec++;
			dst = ft_memset(dst, '0', prec);
			if (str[0] == '-' || str[0] == '+')
				dst[0] = str[0];
			str[0] = '0';
		}
		else
			dst = ft_memset(dst, '0', prec);
		dst = ft_strjoin_per_aux(dst, str);
	}
	else if ((fg->conversion == 's' || fg->conversion == 'S')  && fg->did_p)
		dst = ft_prec_str(str, fg);
	else if (fg->precision == 0 && ft_strequ("0", str) && fg->did_p)
		return ("");
	else
		dst = str;
	return (dst);
}

static char	*ft_flags(char *str, t_format *fg)
{
	char	*dst;

	if (fg->conversion != 'u' && fg->conversion != 'U')
	{
		if (fg->flag->blank && str[0] != '-')
			dst = ft_strjoin_per_aux(" ", str);
		else if (fg->flag->signe && str[0] != '-')
			dst = ft_strjoin_per_aux("+", str);
		else
			dst = str;
	}
	else
		dst = str;
	return (dst);
}

static char	*ft_width(char *str, t_format *fg)
{
	char	*dst;
	int		width;

	width = fg->width - ft_strlen(str);
	if (width > 0)
		dst = ft_putwidth(str, width, fg);
	else
		dst = str;
	return (dst);
}

char		*ft_transfo_int(char *str, t_format *fg)
{
	char	*dst;
	int		prec;

	dst = ft_precision(str, fg);
	dst = ft_flags(dst, fg);
	dst = ft_width(dst, fg);
	return (dst);
}
