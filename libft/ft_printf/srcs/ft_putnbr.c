/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:42:26 by mcastres          #+#    #+#             */
/*   Updated: 2016/12/14 14:25:59 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int n)
{
	int		nb;

	nb = n;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	if (n > -2147483648 && n <= 2147483647)
	{
		if (n < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
			ft_putchar(nb + '0');
	}
}
