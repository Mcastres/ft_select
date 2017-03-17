/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:46:42 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/04 07:49:03 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_opendir(char *directory)
{
	DIR		*dir;

	if (!(dir = opendir(directory)))
	{
		ft_putstr_fd("cd: not a directory: ", 2);
		ft_putstr_fd(directory, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	closedir(dir);
	return (1);
}
