/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_ux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaekim <gaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:32:35 by gaekim            #+#    #+#             */
/*   Updated: 2020/09/08 22:14:31 by gaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_base_ux(long long nbr, char *base, int *cnt, t_tags tags)
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
		putnbr_base_ux(nbr / number_system, base, cnt, tags);
	*cnt += ft_putchar(base[nbr % number_system]);
}

int		print_inside_ux(t_tags tags, int len)
{
	int			i;
	int			cnt;

	cnt = 0;
	i = tags.pre - len;
	while (i-- > 0)
		cnt += ft_putchar('0');
	return (cnt);
}

int		print_outside_ux(t_tags tags, int len, char mode)
{
	int			i;
	int			arg;
	int			cnt;

	cnt = 0;
	arg = (len < tags.pre) ? tags.pre : len;
	i = tags.width - arg;
	while (mode == ' ' && i-- > 0)
		cnt += ft_putchar(' ');
	while (mode == '0' && i-- > 0)
		cnt += ft_putchar('0');
	return (cnt);
}

int		case_ux(char c, t_tags tags, va_list ap)
{
	long long	nbr;
	char		*base;
	int			cnt;
	int			len;

	cnt = 0;
	make_nbr_base(c, ap, &nbr, &base);
	len = converted_len(nbr, (int)ft_strlen(base));
	if (tags.flag == '\0' || (tags.flag == '0' && tags.pre > 0))
		cnt += print_outside_ux(tags, len, ' ');
	if (tags.flag == '0' && (tags.pre == 0 || tags.pre == -1))
		cnt += print_outside_ux(tags, len, '0');
	cnt += print_inside_ux(tags, len);
	putnbr_base_ux(nbr, base, &cnt, tags);
	if (tags.flag == '-')
		cnt += print_outside_ux(tags, len, ' ');
	return (cnt);
}
