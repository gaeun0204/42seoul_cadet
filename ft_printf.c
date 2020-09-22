/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaekim <gaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:32:15 by gaekim            #+#    #+#             */
/*   Updated: 2020/09/08 23:28:12 by gaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_specifier(char c, t_tags tags, va_list ap)
{
	int		ret;

	ret = 0;
	if (c == '%')
		ret = case_pct(tags);
	else if (c == 'c')
		ret = case_c(tags, ap);
	else if (c == 's')
		ret = case_s(tags, ap);
	else if (c == 'p')
		ret = case_p(c, tags, ap);
	else if (c == 'd' || c == 'i')
		ret = case_di(c, tags, ap);
	else if (c == 'u' || c == 'x' || c == 'X')
		ret = case_ux(c, tags, ap);
	else
		return (-1);
	return (ret);
}

int		ft_tag_parsing(const char *format, int i, t_tags *tags, va_list ap)
{
	while (format[i])
	{
		if (ft_is_specifier(format[i]))
			break ;
		if (check_flag(format[i], &tags))
			i++;
		else if (check_width(format[i], &tags, ap))
			i++;
		else if (check_dot(format[i], &tags))
			i++;
		else if (check_precision(format[i], &tags, ap))
			i++;
		else
			return (-1);
	}
	if (tags->signal == 1)
		tags->pre = 0;
	if (format[i] != '%' && format[i] != 's' && format[i] != 'c'
			&& tags->flag == '0' && tags->pre >= 0)
		tags->flag = '\0';
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		cnt;
	t_tags	tags;

	va_start(ap, format);
	i = 0;
	cnt = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			tags = ft_init_tags();
			i = ft_tag_parsing(format, ++i, &tags, ap);
			cnt += ft_specifier(format[i], tags, ap);
		}
		else
			cnt += ft_putchar(format[i]);
		if (i == -1 || cnt == -1)
			break ;
		i++;
	}
	va_end(ap);
	return (cnt);
}
