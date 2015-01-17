/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 03:40:22 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/17 04:12:59 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putprecision(char *str, char *dst, int prec, t_format *fg)
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
	else if (ft_charcheck_in_str(fg->conversion, "sSpdDioOuUxXcC"))
		dst = ft_memset(dst, '0', prec);
	dst = ft_strjoin_per_aux(dst, str);
	return (dst);
}
