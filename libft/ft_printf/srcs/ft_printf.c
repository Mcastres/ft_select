/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 08:44:02 by mcastres          #+#    #+#             */
/*   Updated: 2017/01/05 14:46:54 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_options g_tab_options[] =
{
	{'\0', 0, 0, '\0', '\0', 0}
};

t_func g_tab_func[] =
{
	{'s', '*'},
	{'S', '*'},
	{'p', 'v'},
	{'d', 'i'},
	{'D', 'i'},
	{'i', 'i'},
	{'o', 'u'},
	{'O', 'u'},
	{'u', 'u'},
	{'U', 'u'},
	{'x', 'u'},
	{'X', 'u'},
	{'c', 'c'},
	{'C', 'c'},
	{'\0', '\0'}
};

void	ft_stock_len(va_list ap)
{
	char	c;
	int		i;

	i = 0;
	while (g_tab_func[i].format)
	{
		c = g_tab_options[0].conversion;
		if (g_tab_func[i].format == c && g_tab_func[i].type == 'i')
			ft_print_int(ap);
		else if (g_tab_func[i].format == c && g_tab_func[i].type == '*')
			ft_print_str(ap);
		else if (g_tab_func[i].format == c && g_tab_func[i].type == 'u')
			ft_print_unsigned_int(ap);
		else if (g_tab_func[i].format == c && g_tab_func[i].type == 'c')
			ft_print_char(ap);
		else if (g_tab_func[i].format == c && g_tab_func[i].type == 'v')
			ft_print_str(ap);
		i++;
	}
}

void	ft_stock_options(va_list ap, char const *format, int i)
{
	int		j;
	char	*str;
	int		count;

	j = i + 1;
	count = 0;
	while (!(ft_isalpha(format[j])))
	{
		if (ft_isoptions(format[j]))
			g_tab_options[0].option = format[j++];
		while (ft_isdigit(format[j]))
		{
			count++;
			j++;
		}
		if (count)
		{
			str = ft_strsub(format, (j - count), count);
			g_tab_options[0].largeur = ft_atoi(str);
			count = 0;
		}
	}
	g_tab_options[0].conversion = format[j];
	ft_stock_len(ap);
}

void	ft_reset_tab(void)
{
	g_tab_options[0].option = '\0';
	g_tab_options[0].largeur = 0;
	g_tab_options[0].precision = 0;
	g_tab_options[0].taille = '\0';
	g_tab_options[0].conversion = '\0';
	g_tab_options[0].len = 0;
}

int		ft_printf(char const *format, ...)
{
	va_list		ap;
	int			i;
	int			j;

	i = -1;
	j = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			while (!ft_isalpha(format[j]))
				j++;
			j++;
			ft_stock_options(ap, format, i);
			ft_reset_tab();
		}
		if (i == j)
		{
			ft_putchar(format[i]);
			j++;
		}
	}
	va_end(ap);
	return (i);
}
