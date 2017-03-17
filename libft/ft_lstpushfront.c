/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 18:58:59 by eteyssed          #+#    #+#             */
/*   Updated: 2017/01/21 16:29:55 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfront(t_list **blst, void const *content,
		size_t content_size)
{
	t_list	*list;

	list = *blst;
	if (list)
		list = ft_lstnew(content, content_size);
	else
		*blst = ft_lstnew(content, content_size);
}
