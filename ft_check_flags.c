/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 07:50:56 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/26 17:19:43 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flags_aux(char *my_fg, t_format **fg)
{
	int		i;
	char	*flags;

	i = 0;
	flags = ft_strdup("#0-+* lhjz");
	while (ft_charcheck_in_str(my_fg[i], flags))
	{
		ft_putflags(my_fg[i], fg);
		i++;
	}
	return (i);
}

int		ft_check_flags(const char *str, t_format **fg, va_list ap)
{
	char	*my_fg;
	char	*conversion;
	int		i;
	char	*temp;

	i = 0;
	ft_initflags(fg);
	conversion = ft_strdup("sSpdDioOuUxXcC");
	my_fg = ft_strdup(&str[1]);
	while (my_fg[i] == '*')
	{
		temp = ft_strjoin_etoile(my_fg, ft_itoa(va_arg(ap, int)));
		while (my_fg[i] != '*')
			i++;
		my_fg = ft_strjoin(temp, &my_fg[i + 1]);
	}
	i = ft_check_flags_aux(my_fg, fg);
	(*fg)->width = ft_atoi(&my_fg[i]);
	if ((*fg)->width != 0)
		i += ft_intlen((*fg)->width);
	if (my_fg[i] == '.')
	{
		while (my_fg[i + 1] == '0')
			i++;
		(*fg)->precision = ft_atoi(&my_fg[i + 1]);
		(*fg)->did_p = 1;
		if (!ft_isdigit(my_fg[i + 1]) && my_fg[i] == '.')
			i++;
		else if (!ft_isdigit(my_fg[i + 1]))
			i += 0;
		else
			i += ft_intlen((*fg)->precision) + 1;
	}
	if (my_fg[i] == '0')
		i++;
	if (ft_charcheck_in_str(my_fg[i], conversion))
		(*fg)->conversion = my_fg[i];
	return (i + 1);
}
