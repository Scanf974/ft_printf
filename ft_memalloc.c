/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:39:21 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/08 07:41:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(unsigned int size)
{
	void	*dst;

	dst = NULL;
	if (size)
	{
		dst = malloc(sizeof(dst) * size);
		if (dst)
			ft_bzero(dst, size);
		else
			return (NULL);
	}
	return (dst);
}
