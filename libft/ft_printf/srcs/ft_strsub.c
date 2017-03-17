/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:03:52 by mcastres          #+#    #+#             */
/*   Updated: 2016/12/15 07:58:38 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(s))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	while (i < start)
		i++;
	while (len > 0)
	{
		str[j] = s[i];
		j++;
		i++;
		len--;
	}
	str[j] = '\0';
	return (str);
}
