/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetabb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:46:42 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/14 13:26:41 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetabb(void ***tab, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		ft_freetab((void **)tab[i], ft_tablen((char **)tab[i]));
	free(tab);
	tab = NULL;
}
