/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:46:42 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/17 17:37:49 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		start_term(struct termios *term)
{
	char	*env_term;
	char	*res;

	env_term = getenv("TERM");
	if (tgetent(0, env_term) == -1)
		return (0);
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
	if (!(res = tgetstr("ti", NULL)))
		return (0);
	tputs(res, 0, out_putchar);
	if (!(res = tgetstr("vi", NULL)))
		return (0);
	tputs(res, 0, out_putchar);
	return (1);
}

int		exit_term(struct termios *term)
{
	char	*res;

	if (!(res = tgetstr("te", NULL)))
		return (0);
	tputs(res, 0, out_putchar);
	if (!(res = tgetstr("ve", NULL)))
		return (0);
	tputs(res, 0, out_putchar);
	term->c_lflag |= ICANON;
   	term->c_lflag |= ECHO;
   	tcsetattr(0, 0, term);
   	return (0);
}
