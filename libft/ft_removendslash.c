/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removendslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:46:48 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/09 10:55:19 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_removendslash(char *str)
{
	char	*result;
	int		len;

	len = ft_strlen(str);
	while (str[len] != '/')
		len--;
	result = ft_strsub(str, 0, len);
	return (result);
}
