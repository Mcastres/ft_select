/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:46:42 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/17 17:52:18 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int     voir_touche(t_list *list)
{
  char     buffer[3];

  ft_print_list(list);
  while (1)
  {
    read(0, buffer, 3);
    if (buffer[0] == 27)
      printf("C'est une fleche !\n");
    else if (buffer[0] == 4)
    {
      printf("Ctlr+d, on quitte !\n");
      return (0);
    }
  }
  return (0);
}

int		main(int argc, char **argv)
{
	struct termios	term;
	int				i;
	t_list			*list;

	i = 0;
	list = NULL;
	while (++i < argc)
		ft_lstpushback(&list, argv[i], ft_strlen(argv[i]) + 1);

	start_term(&term);
	voir_touche(list);
	exit_term(&term);


	return (0);
}
