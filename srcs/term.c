/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:46:42 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/18 16:56:03 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		start_term(t_select *list)
{
	char	*env_term;

	env_term = getenv("TERM");
	if (tgetent(0, env_term) == -1)
		return (0);
	if (tcgetattr(0, &list->term) == -1)
		return (-1);
	list->term.c_lflag &= ~(ICANON);
	list->term.c_lflag &= ~(ECHO);
	list->term.c_cc[VMIN] = 1;
	list->term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &list->term);
	tputs(tgetstr("ti", NULL), 0, out_putchar);
	tputs(tgetstr("vi", NULL), 0, out_putchar);
	return (1);
}

int		exit_term(t_select *list)
{
	tputs(tgetstr("te", NULL), 0, out_putchar);
	tputs(tgetstr("ve", NULL), 0, out_putchar);
	list->term.c_lflag |= ICANON;
   	list->term.c_lflag |= ECHO;
   	tcsetattr(0, 0, &list->term);
   	return (0);
}
