/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valide_select.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:19:45 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/22 16:54:48 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_valide_select(t_select **select)
{
	int			i;
	t_select	*s;
	char		**content;

	content = NULL;
	s = *select;
	i = 0;
	while (s->args[i].str)
	{
		if (s->args[i].select == 1)
			content = ft_tabpushback(content, s->args[i].str);
		i++;
	}
	ft_escape(select, content);
}
