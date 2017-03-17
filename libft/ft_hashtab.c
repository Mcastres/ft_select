/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:40:59 by mcastres          #+#    #+#             */
/*   Updated: 2016/11/26 16:00:12 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hashtab(char *str, int tab_size)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		count += str[i];
		i++;
	}
	count %= tab_size;
	return (count);
}
