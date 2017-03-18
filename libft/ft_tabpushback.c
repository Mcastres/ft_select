/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:30:41 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/18 14:12:40 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabpushback(char **tableau, char *content)
{
	char	**new;
	int		i;
	int		size;

	i = -1;
	if (tableau == NULL)
		return ((new = ft_tabcreate(content)));
	size = (ft_tablen(tableau) + 1);
	if (!(new = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (tableau[++i])
		new[i] = ft_strdup(tableau[i]);
	new[i] = ft_strdup(content);
	new[++i] = NULL;
	ft_freetab((void **)tableau, ft_tablen(tableau));
	return (new);
}
