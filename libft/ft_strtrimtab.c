/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:21:37 by mcastres          #+#    #+#             */
/*   Updated: 2017/02/09 11:13:12 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtrimtab(char **tab, char c)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		tab[i] = ft_strtrim_c(tab[i], c);
	}
}
