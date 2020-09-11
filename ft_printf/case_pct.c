/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_pct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaekim <gaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 22:48:28 by gaekim            #+#    #+#             */
/*   Updated: 2020/09/08 19:25:38 by gaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_pct(t_tags tags)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = tags.width - 1;
	while (tags.flag == '\0' && i-- > 0)
		cnt += ft_putchar(' ');
	while (tags.flag == '0' && i-- > 0)
		cnt += ft_putchar('0');
	cnt += ft_putchar('%');
	while (tags.flag == '-' && i-- > 0)
		cnt += ft_putchar(' ');
	return (cnt);
}
