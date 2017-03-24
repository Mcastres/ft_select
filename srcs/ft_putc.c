/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:33:15 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/24 15:40:26 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		color(mode_t mode)
{
	S_ISBLK(mode) ? ft_putstr_fd(C_RED, 2) : NULL;
	S_ISCHR(mode) ? ft_putstr_fd(C_BLUE, 2) : NULL;
	S_ISDIR(mode) ? ft_putstr_fd(C_CYAN, 2) : NULL;
	S_ISFIFO(mode) ? ft_putstr_fd(C_BROWN, 2) : NULL;
	S_ISLNK(mode) ? ft_putstr_fd(C_MAGENTA, 2) : NULL;
	S_ISSOCK(mode) ? ft_putstr_fd(C_GREEN, 2) : NULL;
}

void		ft_putab_inline_c(char **content)
{
	int			i;

	i = 0;
	while (content[i])
	{
		ft_putstr(content[i]);
		if (content[i + 1])
			ft_putstr(" ");
		i++;
	}
}

int			ft_putc(int c)
{
	write(2, &c, 1);
	return (1);
}
