/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:47:43 by mcastres          #+#    #+#             */
/*   Updated: 2016/12/19 14:48:25 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_int(va_list ap)
{
	int		value;
	int		len;

	value = va_arg(ap, int);
	g_tab_options[0].len = ft_intlen(value);
	len = g_tab_options[0].len;
	if (g_tab_options[0].option == '-')
	{
		ft_putnbr(value);
		ft_print_one(len, g_tab_options[0].largeur);
	}
	else if (g_tab_options[0].option == '+')
	{
		ft_print_second(len, g_tab_options[0].largeur);
		ft_putnbr(value);
	}
	else
	{
		ft_print_option(g_tab_options[0].option, len, g_tab_options[0].largeur);
		ft_putnbr(value);
	}
}

void	ft_print_unsigned_int(va_list ap)
{
	unsigned int	value;
	int				len;

	value = va_arg(ap, unsigned int);
	g_tab_options[0].len = ft_unsignedintlen(value);
	len = g_tab_options[0].len;
	if (g_tab_options[0].option == '-')
	{
		ft_putnbru(value);
		ft_print_one(len, g_tab_options[0].largeur);
	}
	else if (g_tab_options[0].option == '+')
	{
		ft_print_second(len, g_tab_options[0].largeur);
		ft_putnbru(value);
	}
	else
	{
		ft_print_option(g_tab_options[0].option, len, g_tab_options[0].largeur);
		ft_putnbru(value);
	}
}

void	ft_print_char(va_list ap)
{
	char	value;

	value = va_arg(ap, int);
	g_tab_options[0].len = 1;
	ft_putchar(value);
}

void	ft_print_str(va_list ap)
{
	char	*value;
	int		len;

	value = va_arg(ap, char *);
	g_tab_options[0].len = ft_strlen(value);
	len = g_tab_options[0].len;
	if (g_tab_options[0].option == '-')
	{
		ft_putstr(value);
		ft_print_one(len, g_tab_options[0].largeur);
	}
	else if (g_tab_options[0].option == '+')
	{
		ft_print_second(len, g_tab_options[0].largeur);
		ft_putstr(value);
	}
	else
	{
		ft_print_option(g_tab_options[0].option, len, g_tab_options[0].largeur);
		ft_putstr(value);
	}
}
