/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:18:18 by mcastres          #+#    #+#             */
/*   Updated: 2017/02/23 15:50:50 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabtrim(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		tab[i] = ft_strtrim_c(ft_strtrim_c(tab[i], 39), 34);
	return (tab);
}
