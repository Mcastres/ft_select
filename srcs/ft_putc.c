/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:33:15 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/24 14:11:04 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_putab_inline_c(char **content)
{
	int			i;

	i = 0;
	while (content[i])
	{
		ft_putstr(content[i]);
		if (content[i + 1])
			ft_putstr(" ");
		i++;
	}
}

int			ft_putc(int c)
{
	write(2, &c, 1);
	return (1);
}
