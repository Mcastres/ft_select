/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:06:06 by mcastres          #+#    #+#             */
/*   Updated: 2016/11/18 12:15:49 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str_src;
	char	*str_dest;

	str_dest = (char *)dest;
	str_src = (char *)src;
	while (n)
	{
		n--;
		str_dest[n] = str_src[n];
	}
	return (str_dest);
}
