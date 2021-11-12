/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:00:21 by snadji-h          #+#    #+#             */
/*   Updated: 2021/11/11 17:45:43 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_strlen4(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_udec(unsigned int nbr, char *base, t_flags flags)
{
	int			i;
	int			len;
	char		tab[1000];
	int			total;

	i = 0;
	total = 0;
	len = ft_strlen4(base);
	if (flags.pos && nbr >= 0)
		total += write(1, "+", 1);
	if (nbr == 0)
		total += write(1, base, 1);
	while (nbr != 0)
	{
		tab[i++] = base[nbr % len];
		nbr = nbr / len;
	}
	while (i != 0)
		total += write(1, &tab[i-- - 1], 1);
	return (total);
}
/*
#include <stdio.h>
int main()
{
	ft_hexbase(31, "0123456789ABCDEF");
}*/
