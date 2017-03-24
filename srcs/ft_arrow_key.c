/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:48:31 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/24 12:02:28 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_up_arrow(t_select **select)
{
	char		*cap;
	t_select	*s;

	s = *select;
	if ((cap = tgetstr("cl", NULL)) == NULL)
		ft_putstr("Cannot clean screen\n");
	else
		tputs(cap, 0, ft_putc);
	if (s->cursor_line == 1)
		s->cursor_line = s->nb_args;
	else
		s->cursor_line--;
	ft_print_all(select, 0, 0);
}

static void	ft_down_arrow(t_select **select)
{
	char		*cap;
	t_select	*s;

	s = *select;
	if ((cap = tgetstr("cl", NULL)) == NULL)
		ft_putstr("Cannot clean screen\n");
	else
		tputs(cap, 0, ft_putc);
	if (s->cursor_line == s->nb_args)
		s->cursor_line = 1;
	else
		s->cursor_line++;
	ft_print_all(select, 0, 0);
}

void		ft_arrow_key(t_select **select, char *buf)
{
	t_select	*s;

	s = *select;
	if (buf[2] == 'A')
		ft_up_arrow(select);
	if (buf[2] == 'B')
		ft_down_arrow(select);
}
