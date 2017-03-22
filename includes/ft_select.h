/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <hmadad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:43:05 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/22 17:31:05 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <../libft/libft.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termcap.h>
# include <term.h>
# include <signal.h>

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

void				suspended(void);
void				abort_term(void);
t_select			*keep_term(t_select *select);
int					ft_signal();
int					ft_find_window_len(t_select **select);
void				print(t_select **select);
void				ft_putab_inline_c(char **content);
void				ft_modify_args(t_select **select, int i, int j);
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
