/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:46:42 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/18 16:54:26 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void 	down_up(t_select *list, int key)
{
	/* Ici ca bug quand tu appuies sur les fleches pour l'instant, fais CTR+C puis relance le programmer et fais echap sinon tu vas pleurer */
	
	if (key == DOWN)
	{
		list->selected++;
		if (list->selected > list->content_size - 1)
			list->selected = 0;
	}
	else
	{
		list->selected--;
		if (list->selected < 0)
			list->selected = list->selected - 1;
	}
}

static void     loop(t_select *list)
{
	unsigned long	key;

	key = 0;
    while (read(0, &key, 6))
    {
		if (key == BACKSPACE || key == DELETE)
			ft_putendl("DELETE");
		else if (key == DOWN || key == UP)
			down_up(list, key);
		else if (key == ESCAPE)
		{
			ft_putendl("DELETE");
			return ;
		}
    }
}

int		main(int argc, char **argv)
{
	t_select		*list;

	if (argc < 2)
		return (ft_printf("Usage : ./ft_select [arg1] ...\n"));
	if (!(list = (t_select *)malloc(sizeof(t_select))))
		return (0);
	init_select(list, argc, argv); 	/* Initialisation de la structure */
	start_term(list);				/* Initialisation du terminal */
	display(list);					/* Fonction qui doit clear la page et afficher les arguments */
	loop(list);						/* Boucle infinie qui interagie en fonction des touche presse comme ta daronne */
	exit_term(list);				/* On quitte le term */
	return (0);
}
