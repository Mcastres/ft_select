/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:46:42 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/04 07:45:39 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_open(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY) < 0))
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}
