/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_commande.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:00:05 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/24 14:04:55 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_delete(t_select **select)
{
	t_select	*s;
	char		*cap;

	s = *select;
	if ((cap = tgetstr("cl", NULL)) == NULL)
		ft_putstr("Cannot clean screen\n");
	else
		tputs(cap, 0, ft_putc);
	ft_modify_args(select, -1, 0);
	ft_print_all(select, 0, 0);
}

void			ft_escape(t_select **select, char **content)
{
	t_select	*s;
	char		*cap;

	s = *select;
	if ((cap = tgetstr("rc", NULL)) == NULL)
		ft_putstr("Cannot restor the cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	if ((cap = tgetstr("cd", NULL)) == NULL)
		ft_putstr("Cannot delete line blow the cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	ft_putstr("\n");
	tputs(tgetstr("te", NULL), 0, ft_putc);
	tputs(tgetstr("ve", NULL), 0, ft_putc);
	s->default_term.c_lflag |= ICANON;
	s->default_term.c_lflag |= ECHO;
	tcsetattr(0, 0, &(s->default_term));
	if (content)
	{
		ft_putab_inline(content);
		ft_freetab((void **)content, ft_tablen(content));
	}
	exit(0);
}

static void		read_again(t_select **select, char *cap)
{
	t_select	*s;

	s = *select;
	if (s->args[s->cursor_line - 1].select == 1)
	{
		s->args[s->cursor_line - 1].select = 0;
		if (s->cursor_line == s->nb_args)
			s->cursor_line = 1;
		else
			s->cursor_line++;
	}
	else if (s->args[s->cursor_line - 1].select == 0)
	{
		s->args[s->cursor_line - 1].select = 1;
		if (s->cursor_line == s->nb_args)
			s->cursor_line = 1;
		else
			s->cursor_line++;
	}
	if ((cap = tgetstr("cl", NULL)) == NULL)
		ft_putstr("Cannot clear screen\n");
	else
		tputs(cap, 0, ft_putc);
	ft_print_all(select, 0, 0);
}

void			ft_read_commande(t_select **select)
{
	t_select	*s;
	char		buf[4];
	char		*cap;

	s = *select;
	cap = NULL;
	while (42)
	{
		ft_bzero(buf, 2);
		read(0, buf, 3);
		if (ft_strcmp(buf, "\n") == 0)
			ft_valide_select(select);
		else if (ft_strcmp(buf, " ") == 0)
			read_again(select, cap);
		else if (buf[0] == 27 && ft_strlen(buf) == 3)
			ft_arrow_key(select, buf);
		else if (buf[0] == 27 && ft_strlen(buf) == 1)
			ft_escape(select, NULL);
		else if (buf[0] == 126 || buf[0] == 127)
			ft_delete(select);
		if (!s->args[0].str)
			ft_escape(select, NULL);
	}
}
