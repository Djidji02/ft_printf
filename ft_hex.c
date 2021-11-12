/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:00:21 by snadji-h          #+#    #+#             */
/*   Updated: 2021/11/11 17:59:17 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

int	ft_strlen2(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_hex(unsigned int nbr, char *base, t_flags flags)
{
	int			i;
	int			len;
	char		tab[1000];
	int			total;

	i = 0;
	total = 0;
	len = ft_strlen2(base);
	if (nbr && flags.hash && base[10] == 'A')
		total += write(1, "0X", 2);
	if (nbr && flags.hash && base[10] == 'a')
		total += write(1, "0x", 2);
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
