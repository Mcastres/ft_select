/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:16:31 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/20 10:50:21 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(t_select **select)
{
	char		*cap;

	ft_init_term(select);
	if ((cap = tgetstr("sc", NULL)) == NULL)
		ft_putstr("Cannot save cursor position\n");
	else
		tputs(cap, 0, ft_putc);
	if ((cap = tgetstr("RA", NULL)) == NULL)
		ft_putstr("Cannot disabled margin auto\n");
	else
		tputs(cap, 0, ft_putc);
	ft_print_all(select);
	ft_read_commande(select);
}
