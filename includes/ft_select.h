/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:21:37 by mcastres          #+#    #+#             */
/*   Updated: 2017/03/17 17:35:07 by mcastres         ###   ########.fr       */
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

int		out_putchar(int c);
int		start_term(struct termios *term);
int		exit_term(struct termios *term);

#endif
