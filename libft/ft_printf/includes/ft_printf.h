/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastres <mcastres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:21:37 by mcastres          #+#    #+#             */
/*   Updated: 2016/12/19 14:44:30 by mcastres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_options
{
	char		option;
	int			largeur;
	int			precision;
	char		taille;
	char		conversion;
	int			len;
}				t_options;

extern t_options g_tab_options[];

typedef struct	s_func
{
	char		format;
	char		type;
}				t_func;

int				ft_printf(const char *format, ...);
void			ft_putchar(char const c);
void			ft_putstr(char const *str);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
void			ft_putnbr(int n);
void			ft_putnbru(unsigned int n);
int				ft_atoi(char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_intlen(int n);
int				ft_unsignedintlen(unsigned int n);
char			*ft_itoa(int n);
char			*ft_strdup(const char *src);
char			ft_isoptions(char c);
void			ft_print_int(va_list ap);
void			ft_print_one(int len, int largeur);
void			ft_print_second(int len, int largeur);
void			ft_print_option(char option, int len, int largeur);
void			ft_print_digit_option(int len, int largeur);
void			ft_print_unsigned_int(va_list ap);
void			ft_print_char(va_list ap);
void			ft_print_str(va_list ap);

#endif
