/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:46:22 by mcastres          #+#    #+#             */
/*   Updated: 2016/12/19 14:47:34 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_one(int len, int largeur)
{
	int		i;

	i = len;
	while (i < largeur)
	{
		ft_putchar(' ');
		i++;
	}
}

void	ft_print_second(int len, int largeur)
{
	int		i;

	i = (len + 1);
	while (i < largeur)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('+');
}

void	ft_print_option(char option, int len, int largeur)
{
	int		i;

	i = len;
	if (!(g_tab_options[0].option))
	{
		ft_print_digit_option(len, largeur);
		return ;
	}
	while (i < largeur)
	{
		ft_putchar(option);
		i++;
	}
}

void	ft_print_digit_option(int len, int largeur)
{
	int		i;

	i = len;
	while (i < largeur)
	{
		ft_putchar(' ');
		i++;
	}
}
