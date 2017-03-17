/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:03:18 by mcastres          #+#    #+#             */
/*   Updated: 2016/12/19 11:39:41 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbru(unsigned int n)
{
	int		nb;

	nb = n;
	if (n <= 4294967295)
	{
		if (nb > 9)
		{
			ft_putnbru(nb / 10);
			ft_putnbru(nb % 10);
		}
		else
			ft_putchar(nb + '0');
	}
}
