/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:22:00 by snadji-h          #+#    #+#             */
/*   Updated: 2021/11/12 15:39:11 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdarg.h>

int	ft_type(int c, va_list args, t_flags flags)
{
	if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr((char *)va_arg(args, char *)));
	else if (c == 'p')
		return (ft_hex_ptr(va_arg(args, void *), "0123456789abcdef"));
	else if (c == 'd')
		return (ft_dec((va_arg(args, int)), "0123456789", flags));
	else if (c == 'i')
		return (ft_dec((va_arg(args, int)), "0123456789", flags));
	else if (c == 'u')
		return (ft_udec((va_arg(args, unsigned int)), "0123456789", flags));
	else if (c == 'x')
		return (ft_hex((va_arg(args, unsigned int)),
				"0123456789abcdef", flags));
	else if (c == 'X')
		return (ft_hex((va_arg(args, unsigned int)),
				"0123456789ABCDEF", flags));
	else
		return (0);
}

t_flags	ft_flags(const char *fmt,	int i, int *mem)
{
	t_flags	flags;

	flags = (t_flags){0};
	while (fmt[i] == ' ' || fmt[i] == '0' || fmt[i] == '+'
		|| fmt[i] == '-' || fmt[i] == '#')
	{
		if (fmt[i] == ' ')
			flags.space = 1;
		if (fmt[i] == '0')
			flags.zero = 1;
		if (fmt[i] == '-')
			flags.neg = 1;
		if (fmt[i] == '+')
			flags.pos = 1;
		if (fmt[i] == '#')
			flags.hash = 1;
		i++;
	}
	*mem = i;
	return (flags);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		total;
	t_flags	flags;
	va_list	args;

	va_start(args, fmt);
	i = 0;
	total = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != 0)
		{
			i++;
			flags = ft_flags(fmt, i, &i);
			total += ft_type(fmt[i], args, flags);
		}
		else
		{
			total += write(1, &fmt[i], 1);
		}
		i++;
	}
	va_end(args);
	return (total);
}
