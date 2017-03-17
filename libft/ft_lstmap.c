/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:24:00 by mcastres          #+#    #+#             */
/*   Updated: 2016/11/25 10:11:58 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	if ((list = (t_list*)malloc(sizeof(*list))) && f && lst)
	{
		list = f(lst);
		if (lst->next)
			list->next = ft_lstmap(lst->next, f);
		return (list);
	}
	return (NULL);
}
