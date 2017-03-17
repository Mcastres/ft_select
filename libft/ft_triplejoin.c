/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triplejoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:02:23 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/08 17:18:06 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_triplejoin(char *s1, char *s2)
{
	char	*temp;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	temp = ft_strjoin(s1, "/");
	tmp = temp;
	temp = ft_strjoin(temp, s2);
	ft_strdel(&tmp);
	return (temp);
}
