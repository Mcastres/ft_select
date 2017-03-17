/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoption.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 09:46:53 by mcastres          #+#    #+#             */
/*   Updated: 2016/12/19 14:46:07 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	ft_isoptions(char c)
{
	if (c == '-')
		return (c);
	if (c == '+')
		return (c);
	if (c == '0')
		return (c);
	if (c == ' ')
		return (c);
	if (c == '#')
		return (c);
	if (c == '%')
		return (c);
	return (0);
}
