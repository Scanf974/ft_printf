/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:25:33 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/08 14:47:01 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	ft_strncpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}
