/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:22:00 by snadji-h          #+#    #+#             */
/*   Updated: 2021/11/05 18:46:31 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdarg.h>

int	ft_fonction(int c, va_list args)
{
	if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr((char *)va_arg(args, char *)));
	else
		return (0);
}
int	ft_printf(const char *fmt, ...)
{
	int i;

	va_list	args;
	va_start(args, fmt);

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != 0)
		{
			i++;
			ft_fonction(fmt[i], args);
		}
		else
		{
			write(1, &fmt[i], 1);
		}
		i++;
	}	

	va_end(args);
	return (0);
}
