/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:46:48 by mcastres          #+#    #+#             */
/*   Updated: 2016/12/15 07:58:46 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_atoi(char *str)
{
	int		nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (*str == '\t' || *str == ' ' || *str == '\v'
			|| *str == '\n' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		sign = (-1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= 48 && *str <= 57)
	{
		nb *= 10;
		nb += (*str - '0');
		str++;
	}
	return (nb * sign);
}
