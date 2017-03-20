/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:30:41 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/08 11:45:48 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabpushback(char **tab, char *content)
{
	char	**new;
	int		i;
	int		size;

	i = -1;
	if (tab == NULL)
		return ((new = ft_tabcreate(content)));
	size = (ft_tablen(tab) + 1);
	if (!(new = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (tab[++i])
		new[i] = ft_strdup(tab[i]);
	new[i] = ft_strdup(content);
	new[++i] = NULL;
	ft_freetab((void **)tab, ft_tablen(tab));
	return (new);
}
