/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:02:23 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/10 15:21:32 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getcwd(void)
{
	char	*temp;
	int		size;

	size = 254;
	if (!(temp = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	getcwd(temp, size);
	return (temp);
}
