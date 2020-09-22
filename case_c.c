/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaekim <gaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:16:43 by gaekim            #+#    #+#             */
/*   Updated: 2020/09/05 17:36:22 by gaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_c(t_tags tags, va_list ap)
{
	int		cnt;
	int		i;
	char	c;

	cnt = 0;
	i = tags.width - 1;
	c = (char)va_arg(ap, int);
	while (tags.flag != '-' && i-- > 0)
		cnt += ft_putchar(' ');
	cnt += ft_putchar(c);
	while (tags.flag == '-' && i-- > 0)
		cnt += ft_putchar(' ');
	return (cnt);
}
