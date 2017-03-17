/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:23:36 by mcastres          #+#    #+#             */
/*   Updated: 2017/02/06 13:26:32 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*list_temp;

	list = *alst;
	while (list)
	{
		list_temp = list->next;
		del(list->content, list->content_size);
		free(list);
		list = list_temp;
	}
	*alst = NULL;
}
