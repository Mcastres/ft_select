/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:40:50 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/21 09:43:27 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_modify_args(t_select **select, int nb)
{
	t_select	*s;
	t_args		*new;
	int			i;
	int			j;

	s = *select;
	i = -1;
	j = 0;
	if (!(new = (t_args *)malloc(sizeof(t_args) * nb)))
		return ;
	new[nb].str = NULL;
	while (++i < nb)
	{
		if (i != s->cursor_line - 1)
			new[j].str = ft_strdup(s->args[i].str);
		else
			j--;
		new[i].select = 0;
		j++;
	}
	s->args = new;
	s->nb_args--;
	if (s->cursor_line - 1 == s->nb_args)
		s->cursor_line--;
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
		ft_select(&select);
	}
	return (0);
}
