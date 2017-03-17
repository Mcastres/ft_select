/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:18:18 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/17 15:16:45 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabtrim(char **tableau)
{
	int		i;

	i = -1;
	while (tableau[++i])
		tableau[i] = ft_strtrim_c(ft_strtrim_c(tableau[i], 39), 34);
	return (tableau);
}
