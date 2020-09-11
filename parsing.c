/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaekim <gaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 21:05:58 by gaekim            #+#    #+#             */
/*   Updated: 2020/09/08 22:11:04 by gaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(char c, t_tags **tags)
{
	if ((*tags)->flag != '-' && (c == '0' || c == '-')
			&& !((*tags)->width) && (*tags)->dot == 0)
	{
		(*tags)->flag = c;
		return (1);
	}
	else if ((c == '-' || c == '0') && (*tags)->width == 0 && (*tags)->dot == 0)
		return (1);
	return (0);
}

int	check_width(char c, t_tags **tags, va_list ap)
{
	int	ret;

	ret = 1;
	if (ft_isdigit(c) && (*tags)->dot == 0)
	{
		(*tags)->width = ((*tags)->width * 10) + (c - '0');
		((*tags)->width < 0) ? ((*tags)->width *= -1) : 0;
	}
	else if (c == '*' && (*tags)->dot == 0)
	{
		(*tags)->width = va_arg(ap, int);
		if ((*tags)->width < 0)
		{
			(*tags)->width = (*tags)->width * (-1);
			(*tags)->flag = '-';
		}
	}
	else
		ret = 0;
	return (ret);
}

int	check_dot(char c, t_tags **tags)
{
	if (c == '.')
	{
		(*tags)->dot = 1;
		(*tags)->pre = 0;
		return (1);
	}
	return (0);
}

int	check_precision(char c, t_tags **tags, va_list ap)
{
	int	ret;

	ret = 1;
	if (c == '-' && (*tags)->dot == 1)
		(*tags)->signal = 1;
	else if (ft_isdigit(c) && (*tags)->dot == 1)
	{
		(*tags)->pre = ((*tags)->pre * 10) + (c - '0');
		if ((*tags)->signal == 1)
		{
			(*tags)->flag = '-';
			(*tags)->width = (*tags)->pre;
		}
	}
	else if (c == '*' && (*tags)->dot == 1)
	{
		(*tags)->pre = va_arg(ap, int);
		if ((*tags)->pre < 0)
			(*tags)->pre = -1;
	}
	else
		ret = 0;
	return (ret);
}
