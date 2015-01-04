/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:44:59 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/08 07:38:43 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(unsigned int size)
{
	char	*dst;

	dst = ft_memalloc(size + 1);
	if (!dst)
		return (NULL);
	return (dst);
}
