/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:33:15 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/22 14:48:25 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	color(mode_t mode)
{
	S_ISBLK(mode) ? ft_putstr(C_RED) : NULL;
	S_ISCHR(mode) ? ft_putstr(C_BLUE) : NULL;
	S_ISDIR(mode) ? ft_putstr(C_CYAN) : NULL;
	S_ISFIFO(mode) ? ft_putstr(C_BROWN) : NULL;
	S_ISREG(mode) ? ft_putstr(C_NONE) : NULL;
	S_ISLNK(mode) ? ft_putstr(C_MAGENTA) : NULL;
	S_ISSOCK(mode) ? ft_putstr(C_GREEN) : NULL;
}

void	ft_putab_inline_c(char **content)
{
	struct stat	sb;
	int			i;

	i = 0;
	while (content[i])
	{
		lstat(content[i], &sb);
		color(sb.st_mode);
		ft_putstr(C_RED);
		ft_putstr(content[i]);
		ft_putstr(C_NONE);
		if (content[i + 1])
			ft_putstr(" ");
		i++;
	}
}

int		ft_putc(int c)
{
	write(2, &c, 1);
	return (1);
}
