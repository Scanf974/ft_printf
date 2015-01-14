/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 09:43:21 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/13 16:48:49 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_int(va_list ap, t_format *fg)
{
	long long int	nb;
	char			*dst;

	nb = va_arg(ap, long long int);
	if (fg->conversion == 'D')
		nb = (long int)nb;
	else if (fg->over_flag->l_z)
		nb = (unsigned long long int)nb;
	else if (fg->over_flag->l_long == 1)
		nb = (long)nb;
	else if (fg->over_flag->l_long == 2)
		nb = (long long)nb;
	else if (fg->over_flag->l_intmax_t)
		nb = (intmax_t)nb;
	else if (fg->over_flag->l_short == 1)
		nb = (short int)nb;
	else if (fg->over_flag->l_short == 2)
		nb = (signed char)nb;
	else if (!fg->over_flag->l_long)
		nb = (int)nb;
	dst = ft_long_itoa(nb);
	return (ft_transfo_int(dst, fg));
}

static char	*ft_hex(va_list ap, t_format *fg)
{
	unsigned long long int	nb;
	char					*dst;

	nb = va_arg(ap, unsigned long long int);
	if (fg->over_flag->l_short == 2)
		nb = (unsigned char)nb;
	else if (fg->conversion == 'p')
		nb = (unsigned long int)nb;
	else if (fg->over_flag->l_z)
		nb = (unsigned long int)nb;
	else if (fg->over_flag->l_short == 1)
		nb = (unsigned short)nb;
	else if (fg->over_flag->l_long == 1)
		nb = (unsigned long)nb;
	else if (fg->over_flag->l_intmax_t)
		nb = (uintmax_t)nb;
	else if (!fg->over_flag->l_long)
		nb = (unsigned int)nb;
	dst = ft_bin_to_hexoct(ft_binary(nb, fg), HEX, fg);
	return (ft_transfo_hexoct(dst, fg));
}

static char	*ft_oct(va_list ap, t_format *f)
{
	unsigned long long int	nb;
	char					*dst;

	nb = va_arg(ap, unsigned long long int);
	if (f->conversion == 'U' || f->conversion == 'O'
			|| f->over_flag->l_long == 1)
		nb = (unsigned long)nb;
	else if (f->over_flag->l_z)
		nb = (unsigned long int)nb;
	else if (f->over_flag->l_short == 2)
		nb = (unsigned char)nb;
	else if (f->over_flag->l_short)
		nb = (unsigned short)nb;
	else if (f->over_flag->l_intmax_t)
		nb = (uintmax_t)nb;
	else if (!f->over_flag->l_long)
		nb = (unsigned int)nb;
	if (f->conversion == 'u' || f->conversion == 'U')
		dst = ft_transfo_int(ft_unsigned_itoa(nb), f);
	else
		dst = ft_transfo_hexoct(ft_bin_to_hexoct(ft_binary(nb, f), OCT, f), f);
	return (dst);
}

static char	*ft_cac(va_list ap, t_format *fg)
{
	int				nb;
	char			*bin;
	char			*dst;
	int				i;

	i = 0;
	nb = va_arg(ap, int);
	if (nb > 127 && (fg->conversion == 'C' || (fg->conversion == 'c' && fg->over_flag->l_long)))
	{
		bin = ft_binary(nb, fg);
		dst = ft_split_bytes(bin);
	}
	else
	{
		dst = (char *)malloc(sizeof(char) * 2);
		dst[0] = nb;
		dst[1] = '\0';
	}
	return (ft_transfo_int(dst, fg));
}

char		*ft_putarg(const char *f, va_list ap, t_format *fg)
{
	char			*dst;
	char			*bin;
	char			*temp;
	int				i;
	int				*tab;

	tab = (int *)malloc(sizeof(int) * 65);
	dst = (char *)malloc(sizeof(char) * (2));
	dst[1] = '\0';
	while (ft_charcheck_in_str(*f, "#0-+ *lhjz"))
		f++;
	if (*f == 'c' || *f == 'C')
		dst = ft_cac(ap, fg);
	else if (*f == 'd' || *f == 'i' || *f == 'D')
		dst = ft_int(ap, fg);
	else if (*f == 'x' || *f == 'X' || *f == 'p')
		dst = ft_hex(ap, fg);
	else if (*f == 'o' || *f == 'O' || *f == 'u' || *f == 'U')
		dst = ft_oct(ap, fg);
	else if (*f == 's' || *f == 'S')
	{
		if (*f == 'S' || (*f == 's' && fg->over_flag->l_long))
		{
			tab = va_arg(ap, int *);
			temp = (char *)malloc(sizeof(char) * 2);
			i = 0;
			if (!tab)
				dst = ft_strdup("(null)");
			else
			{
				while (tab[i])
				{
					if (tab[i] > 127)
					{
						bin = ft_binary(tab[i], fg);
						temp = ft_split_bytes(bin);
					}
					else
					{
						temp[0] = tab[i];
						temp[1] = '\0';
					}
					dst = ft_strjoin(dst, temp);
					i++;
				}
			}
			dst = ft_transfo_int(dst, fg);
		}
		else
		{
			dst = va_arg(ap, char *);
			if (!dst)
				dst = ft_strdup("(null)");
			dst = ft_transfo_int(dst, fg);
		}
	}
	else
	{
		dst[0] = *f;
		dst = ft_transfo_int(dst, fg);
	}
	return (dst);
}
