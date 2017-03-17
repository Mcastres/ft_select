/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:07:12 by mcastres          #+#    #+#             */
/*   Updated: 2016/11/22 10:01:48 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str_src;
	char	*str_dest;
	size_t	i;

	str_dest = (char *)dest;
	str_src = (char *)src;
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			str_dest[i] = str_src[i];
			i++;
		}
	}
	else
	{
		while (n)
		{
			n--;
			str_dest[n] = str_src[n];
		}
	}
	return (dest);
}
