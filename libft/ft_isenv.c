/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:46:42 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/20 09:37:18 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isenv(char *env_line, char *name)
{
	int		i;

	i = 0;
	while (env_line[i] == name[i])
		i++;
	if (env_line[i] == '=' && !name[i])
		return (1);
	else
		return (0);
}
