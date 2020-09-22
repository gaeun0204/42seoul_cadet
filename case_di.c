/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaekim <gaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:32:35 by gaekim            #+#    #+#             */
/*   Updated: 2020/09/08 22:14:04 by gaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_base_di(long long nbr, char *base, int *cnt, t_tags tags)
{
	int			number_system;

	if (nbr == 0 && tags.dot == 1 && tags.pre == 0)
	{
		if (tags.width >= 1)
			*cnt += ft_putchar(' ');
		return ;
	}
	number_system = (int)ft_strlen(base);
	if (nbr >= number_system)
		putnbr_base_di(nbr / number_system, base, cnt, tags);
	*cnt += ft_putchar(base[nbr % number_system]);
}

int		print_inside_di(t_tags tags, int len, int minus)
{
	int			i;
	int			cnt;

	cnt = 0;
	i = (tags.pre + minus) - len;
	while (i-- > 0)
		cnt += ft_putchar('0');
	return (cnt);
}

int		print_outside_di(t_tags tags, int len, int minus, char mode)
{
	int			i;
	int			arg;
	int			cnt;

	cnt = 0;
	arg = (len < (tags.pre + minus)) ? (tags.pre + minus) : len;
	i = tags.width - arg;
	while (mode == ' ' && i-- > 0)
		cnt += ft_putchar(' ');
	while (mode == '0' && i-- > 0)
		cnt += ft_putchar('0');
	return (cnt);
}

int		case_di(char c, t_tags tags, va_list ap)
{
	long long	nbr;
	char		*base;
	int			cnt;
	int			len;
	int			minus;

	cnt = 0;
	make_nbr_base(c, ap, &nbr, &base);
	minus = (nbr < 0) ? 1 : 0;
	len = converted_len(nbr, (int)ft_strlen(base));
	if (tags.flag == '\0' || (tags.flag == '0' && tags.pre > 0))
		cnt += print_outside_di(tags, len, minus, ' ');
	(minus == 1) ? (cnt += ft_putchar('-')) : 0;
	if (tags.flag == '0' && (tags.pre == 0 || tags.pre == -1))
		cnt += print_outside_di(tags, len, minus, '0');
	cnt += print_inside_di(tags, len, minus);
	(nbr < 0) ? putnbr_base_di(-nbr, base, &cnt, tags)
		: putnbr_base_di(nbr, base, &cnt, tags);
	if (tags.flag == '-')
		cnt += print_outside_di(tags, len, minus, ' ');
	return (cnt);
}
