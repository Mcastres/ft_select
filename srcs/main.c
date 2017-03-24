/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:40:50 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/24 14:20:31 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		abort_term(void)
{
	t_select	*s;

	s = keep_term(NULL);
	s->default_term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, &(s->default_term));
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	exit(EXIT_FAILURE);
}

static void	ft_modify(t_select **select)
{
	t_select	*s;

	s = *select;
	s->nb_args--;
	if (s->cursor_line - 1 == s->nb_args)
		s->cursor_line--;
}

void		ft_modify_args(t_select **select, int i, int j)
{
	t_select	*s;
	t_args		*new;

	s = *select;
	if (!(new = (t_args *)malloc(sizeof(t_args) * s->nb_args)))
		return ;
	while (++i < s->nb_args)
	{
		if (i != s->cursor_line - 1)
		{
			new[j].str = ft_strdup(s->args[i].str);
			ft_strdel(&s->args[i].str);
		}
		else
		{
			j--;
			ft_strdel(&s->args[i].str);
		}
		new[j].select = 0;
		j++;
	}
	new[j].str = NULL;
	free(s->args);
	s->args = new;
	ft_modify(select);
}

static int	ft_init_args(t_select **select, char **av, int ac)
{
	t_select	*s;
	t_args		*args;
	int			i;
	int			len;

	s = *select;
	i = 0;
	if (!(args = (t_args *)malloc(sizeof(t_args) * ac)))
		return (0);
	args[ac - 1].str = NULL;
	while (av[i])
	{
		if ((len = ft_strlen(av[i])) > s->max_strlen)
			s->max_strlen = len;
		args[i].str = ft_strdup(av[i]);
		args[i].select = 0;
		i++;
	}
	s->args = args;
	return (0);
}

int			main(int ac, char **av, char **env)
{
	t_select	*select;

	if (!(select = (t_select *)malloc(sizeof(t_select))))
		return (0);
	select->nb_args = ac - 1;
	select->cursor_line = 1;
	select->max_strlen = 0;
	if (ac > 1)
	{
		select->env = ft_tabdup(env);
		ft_init_args(&select, (av + 1), ac);
		keep_term(select);
		ft_signal(av);
		ft_select(&select);
	}
	else
		ft_putendl("Usage: ./ft_select [argv1] ...");
	return (0);
}
