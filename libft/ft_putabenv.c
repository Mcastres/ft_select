/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putabenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:46:48 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/17 15:14:58 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putabenv(char **tableau)
{
	int		i;

	i = 0;
	while (tableau[++i])
		ft_putendl(tableau[i]);
	return (1);
}
