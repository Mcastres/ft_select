/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabbpushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:30:41 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/17 15:15:46 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	***ft_tabbpushback(char ***tableau, char **content)
{
	char	***new;
	int		i;
	int		size;

	i = -1;
	if (tableau == NULL)
		return ((new = ft_tabbcreate(content)));
	size = (ft_tabblen(tableau) + 1);
	if (!(new = (char ***)malloc(sizeof(char **) * size + 1)))
		return (NULL);
	while (tableau[++i])
		new[i] = ft_tabdup(tableau[i]);
	new[i] = ft_tabdup(content);
	new[++i] = NULL;
	ft_freetabb((void ***)tableau, ft_tabblen(tableau));
	return (new);
}
