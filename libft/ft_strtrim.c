/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:29:16 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/02 15:43:33 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	j;

	if (!s)
		return (NULL);
	ft_tabtospace((char *)s);
	i = 0;
	j = 0;
	len = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (!(s[i]) || ft_strlen(s) == 0 || !s)
		return (ft_strsub(s, 0, 0));
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && s[len])
		len--;
	if (!(str = (char *)malloc(sizeof(*str) * (len - i) + 2)))
		return (NULL);
	while (i < len + 1)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
