/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:43:05 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/20 16:50:33 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <../libft/libft.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
# include <termcap.h>
# include <term.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

typedef	struct		s_args
{
	char	*str;
	int		select;
}					t_args;

typedef struct		s_select
{
	struct termios	default_term;
	t_args			*args;
	char			**env;
	int				width;
	int				height;
	int				nb_args;
	int				cursor_line;
	int				max_strlen;
}					t_select;

void				ft_modify_args(t_select **select, int nb);
void				ft_select(t_select **select);
void				ft_init_term(t_select **select);
void				ft_read_commande(t_select **select);
void				ft_valide_select(t_select **select);
void				ft_arrow_key(t_select **select, char *buf);
void				ft_print_all(t_select **select);
void				ft_escape(t_select **select, char **content);
void				ft_valide_select(t_select **select);
int					ft_putc(int c);

#endif
