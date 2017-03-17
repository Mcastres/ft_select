/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:02:23 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/08 17:17:03 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		temp;
	size_t		i;
	size_t		words;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_words((char *)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	tab[words] = NULL;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		temp = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > temp)
			tab[words++] = ft_strsub((s + temp), 0, (i - temp));
	}
	return (tab);
}
