/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaekim <gaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:31:00 by gaekim            #+#    #+#             */
/*   Updated: 2020/09/08 22:13:18 by gaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_tags
{
	char	flag;
	int		width;
	int		dot;
	int		pre;
	int		signal;
}				t_tags;

int				ft_printf(const char *format, ...);
int				ft_tag_parsing(const char *format, int i, t_tags *tags, \
		va_list ap);
int				ft_specifier(char c, t_tags tags, va_list ap);

int				check_flag(char c, t_tags **tags);
int				check_width(char c, t_tags **tags, va_list ap);
int				check_dot(char c, t_tags **tags);
int				check_precision(char c, t_tags **tags, va_list ap);

int				case_pct(t_tags tags);
int				case_c(t_tags tags, va_list ap);
int				case_s(t_tags tags, va_list ap);

int				case_p(char c, t_tags tags, va_list ap);
int				case_di(char c, t_tags tags, va_list ap);
int				case_ux(char c, t_tags tags, va_list ap);

size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);

int				ft_putchar(char c);
int				ft_is_specifier(char c);

t_tags			ft_init_tags(void);
int				converted_len(long long n, int base_num);
void			make_nbr_base(char c, va_list ap, long long *nbr, char **base);

#endif
