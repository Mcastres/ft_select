/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:47:50 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/24 14:22:37 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select		*keep_term(t_select *select)
{
	static t_select		*temp = NULL;

	if (select)
		temp = select;
	return (temp);
}

static void		suspended(void)
{
	t_select	*s;
	char		cp[2];

	s = keep_term(NULL);
	s->default_term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, &(s->default_term));
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	signal(SIGTSTP, SIG_DFL);
	cp[0] = s->default_term.c_cc[VSUSP];
	cp[1] = 0;
	ioctl(0, TIOCSTI, cp);
}

static void		continue_term(void)
{
	t_select	*s;

	s = keep_term(NULL);
	ft_init_term(&s);
	ft_putstr_fd("ft_select restored, press an arrow key", 2);
}

static void		sig_handler(int signo)
{
	if (signo == SIGCONT)
		continue_term();
	else if (signo == SIGTSTP)
		suspended();
	else
		abort_term();
}

int				ft_signal(void)
{
	if (signal(SIGCONT, sig_handler) == SIG_ERR)
		ft_putstr_fd("\ncan't catch SIGCONT\n", 2);
	if (signal(SIGTSTP, sig_handler) == SIG_ERR)
		ft_putstr_fd("\ncan't catch SIGTSTP\n", 2);
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_putstr_fd("\ncan't catch SIGINT\n", 2);
	return (0);
}
