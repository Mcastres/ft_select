/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:34:19 by mcastres          #+#    #+#             */
/*   Updated: 2016/11/28 09:09:06 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		on_est_42(char c)
{
	int		rot;

	rot = 0;
	while (rot < 16)
	{
		if (c == 'Z')
			c = 'A' - 1;
		if (c == 'z')
			c = 'a' - 1;
		c++;
		rot++;
	}
	return (c);
}

char			*ft_rot42(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = on_est_42(str[i]);
		i++;
	}
	return (str);
}
