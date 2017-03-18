/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:21:37 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/18 16:56:01 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <termcap.h>
# include <termios.h>
# include <term.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# define ESCAPE     27
# define SPACE      32
# define UP         4283163
# define LEFT       4479771
# define RIGHT      4414235
# define DOWN       40
# define RETURN     10
# define DELETE     127
# define BACKSPACE  2117294875

typedef struct		s_select
{
	char				**content;		/* Les arguments passe en parametre */
	int					selected;		/* l'argument selectionne */
	int					content_size; 	/* Nombre d'arguments */
	struct termios		term;			/* Ca tu connais bg */
}					t_select;

void 		display(t_select *list);
void		init_select(t_select *list, int argc, char **argv);
int			out_putchar(int c);
int			start_term(t_select *list);
int			exit_term(t_select *list);

#endif
