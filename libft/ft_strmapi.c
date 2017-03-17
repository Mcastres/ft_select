/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:13:10 by mcastres          #+#    #+#             */
/*   Updated: 2016/11/23 14:59:58 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	p;
	char			*str;
	size_t			i;
	size_t			len;

	if (!s)
		return (NULL);
	i = 0;
	p = i;
	len = ft_strlen(s) + 1;
	if (!(str = (char *)malloc(sizeof(*str) * len)))
		return (NULL);
	while (s[i])
	{
		str[i] = f(p, s[i]);
		i++;
		p++;
	}
	str[i] = '\0';
	return (str);
}
