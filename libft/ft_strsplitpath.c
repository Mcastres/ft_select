/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitpath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:02:23 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/08 17:10:16 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplitpath(char *command, int slash)
{
	char		**tab;
	char		*temp;
	int			i;

	tab = ft_strsplit(command, '/');
	while (tab[i])
	{
		temp = tab[i];
		if (command[0] == '/' && i == 0)
			temp = ft_strjoin('/', tab[i]);
		lstat(temp, &sb);
	}
}
