/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_etoile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 16:57:39 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/22 17:10:02 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen_et(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '*')
		i++;
	return (i);
}

char	*ft_strjoin_etoile(const char *s1, const char *s2)
{
	int		len_all;
	char	*dst;

	if (s1 && s2)
	{
		len_all = ft_strlen_et(s1) + ft_strlen_et(s2);
		dst = ft_memalloc(len_all + 1);
		if (dst)
		{
			ft_strncpy(dst, s1, ft_strlen_et(s1));
			ft_strncat(dst, s2, ft_strlen_et(s2));
			return (dst);
		}
	}
	return (NULL);
}
