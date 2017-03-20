/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 18:58:59 by eteyssed          #+#    #+#             */
/*   Updated: 2017/01/10 16:41:54 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **blst, void const *content,
		size_t content_size)
{
	t_list	*list;

	list = *blst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(content, content_size);
	}
	else
		*blst = ft_lstnew(content, content_size);
}
