/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:30:41 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/17 15:16:07 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdelone(char **data, char *content, int size, int j)
{
	char	**new;
	char	*name;
	int		i;
	int		k;

	i = -1;
	if (!(new = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (++i < size)
	{
		k = 0;
		while (data[i][k] != '=')
			k++;
		name = ft_strsub(data[i], 0, k);
		if (!(ft_strcmp(name, content) == 0))
			new[j] = ft_strdup(data[i]);
		else
			j--;
		j++;
		ft_strdel(&name);
	}
	new[j] = NULL;
	ft_freetab((void **)data, ft_tablen(data));
	return (new);
}
