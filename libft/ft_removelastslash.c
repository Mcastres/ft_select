/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removelastslash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:46:48 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/11 15:57:11 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_removelastslash(char *str)
{
	char	*result;
	int		len;

	result = NULL;
	len = ft_strlen(str);
	if (str[len - 1] == '/' && !str[len])
	{
		while (str[len - 1] == '/')
			len--;
		result = ft_strsub(str, 0, len);
		return (result);
	}
	return (str);
}
