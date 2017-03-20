/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putab_inline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:19:45 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/20 16:52:35 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putab_inline(char **content)
{
	int		i;

	i = 0;
	while (content[i])
	{
		ft_putstr(content[i]);
		if (content[i + 1])
			ft_putstr(" ");
		i++;
	}
}
