/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:00:21 by snadji-h          #+#    #+#             */
/*   Updated: 2021/11/12 15:51:18 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_strlen3(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_flags2(int nbr, t_flags flags)
{
	if (flags.pos && nbr >= 0)
		return (write(1, "+", 1));
	else if (flags.space && nbr >= 0)
		return (write(1, " ", 1));
	return (0);
}

int	ft_poubelle(int nbr, char *base)
{
	int		len;
	int		i;
	int		total;
	char	tab[1000];

	len = ft_strlen3(base);
	i = 0;
	total = 0;
	if (nbr < 0)
	{
		total += write(1, "-", 1);
		nbr = nbr * -1;
	}
	while (nbr != 0)
	{
		tab[i++] = base[nbr % len];
		nbr = nbr / len;
	}
	while (i != 0)
		total += write(1, &tab[i-- - 1], 1);
	return (total);
}

int	ft_dec(int nbr, char *base, t_flags flags)
{
	int	total;

	total = 0;
	if ((flags.pos && nbr >= 0) || (flags.space && nbr >= 0))
		total = ft_flags2(nbr, flags);
	if (nbr == 0)
		total += write(1, base, 1);
	else if (nbr == INT_MIN)
		total += write(1, "-2147483648", 11);
	else
		total += ft_poubelle(nbr, base);
	return (total);
}
/*
#include <stdio.h>
int main()
{
	ft_hexbase(31, "0123456789ABCDEF");
}*/
