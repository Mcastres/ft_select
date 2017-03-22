/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:06:21 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/22 17:33:19 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		print_else(t_select **select, int i, char *cap, int len)
{
	t_select	*s;

	s = *select;
	ft_putstr_fd("    ", 2);
	if (s->args[i].select == 1)
	{
		if ((cap = tgetstr("mr", NULL)) == NULL)
			ft_putstr("Cannot set reverse video mode\n");
		else
			tputs(cap, 0, ft_putc);
	}
	ft_putstr_fd(s->args[i].str, 2);
	if (s->args[i].select == 1)
	{
		if ((cap = tgetstr("me", NULL)) == NULL)
			ft_putstr("Cannot set the end of all appearance mode\n");
		else
			tputs(cap, 0, ft_putc);
	}
	while (len-- > 0)
		ft_putchar_fd(' ', 2);
	ft_putchar_fd('\n', 2);
}

static void		print_close(t_select **select, int i, char *cap)
{
	t_select	*s;

	s = *select;
	if (s->args[i].select == 1)
	{
		if ((cap = tgetstr("me", NULL)) == NULL)
			ft_putstr("Cannot set the end of all appearance mode\n");
		else
			tputs(cap, 0, ft_putc);
	}
}

static void		print_again(t_select **select, int i, char *cap)
{
	t_select	*s;

	s = *select;
	if (s->args[i].select == 1)
	{
		if ((cap = tgetstr("mr", NULL)) == NULL)
			ft_putstr("Cannot set reverse video mode\n");
		else
			tputs(cap, 0, ft_putc);
	}
	if ((cap = tgetstr("us", NULL)) == NULL)
		ft_putstr("Cannot set the underline mode\n");
	else
		tputs(cap, 0, ft_putc);
	ft_putstr_fd(s->args[i].str, 2);
	if ((cap = tgetstr("ue", NULL)) == NULL)
		ft_putstr("Cannot set the end of underline mode\n");
	else
		tputs(cap, 0, ft_putc);
	print_close(select, i, cap);
}

void			ft_print_all(t_select **select)
{
	t_select	*s;
	int			i;
	int			j;
	int			temp;
	int			len;
	char		*cap;

	i = 0;
	temp = 0;
	s = *select;
	j = s->height;
	cap = NULL;
	if (!ft_find_window_len(select))
	{
		ft_putstr_fd("Screen too small", 2);
		return ;
	}
	while (s->args[i].str)
	{
		j = 1;
		if (temp >= s->height - 2)
		{
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, j), 2);
			j++;
			temp = -1;
		}
		len = s->max_strlen - ft_strlen(s->args[i].str) + 3;
		if (i == (s->cursor_line - 1))
		{
			ft_putstr_fd("  > ", 2);
			ft_putstr_fd(C_CYAN, 2);
			print_again(select, i, cap);
			ft_putstr_fd(C_NONE, 2);
			ft_putchar(' ');
			ft_putstr_fd("<\n", 2);
		}
		else
			print_else(select, i, cap, len);
		i++;
		temp++;
	}
}
