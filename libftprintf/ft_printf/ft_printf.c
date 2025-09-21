/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:21:27 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/07/30 23:05:59 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	whichcontent(char fmt, va_list args)
{
	if (fmt == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (fmt == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (fmt == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (fmt == 'x' || fmt == 'X')
		return (ft_print_hex(va_arg(args, int), fmt));
	else if (fmt == 'u')
		return (ft_print_unsigned(va_arg(args, int)));
	else if (fmt == '%')
	{
		return (ft_print_char('%'));
	}
	else
	{
		ft_print_char('%');
		ft_print_char(fmt);
		return (2);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			len;
	int			len_ctrl;
	va_list		args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len_ctrl = whichcontent(format[++i], args);
		}
		else
		{
			len_ctrl = ft_print_char(format[i]);
		}
		if (len_ctrl == -1)
			return (-1);
		len += len_ctrl;
		i++;
	}
	va_end(args);
	return (len);
}
