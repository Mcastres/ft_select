/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:19:50 by mcastres          #+#    #+#             */
/*   Updated: 2016/11/18 13:05:49 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*str_src;
	char	*str_dest;
	size_t	i;

	str_dest = (char *)dest;
	str_src = (char *)src;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str_src[i] == (unsigned char)c)
		{
			str_dest[i] = (unsigned char)str_src[i];
			return ((char *)str_dest + (i + 1));
		}
		str_dest[i] = (unsigned char)str_src[i];
		i++;
	}
	return (NULL);
}
