/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:00:21 by snadji-h          #+#    #+#             */
/*   Updated: 2021/11/11 18:00:10 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

int	ft_hex_ptr(void *ptr, char *base)
{
	int				i;
	unsigned long	nbr;
	char			tab[1000];
	int				total;

	i = 0;
	total = 0;
	nbr = (unsigned long) ptr;
	total += write(1, "0x", 2);
	if (nbr == 0)
		total += write(1, base, 1);
	while (nbr != 0)
	{
		tab[i++] = base[nbr % 16];
		nbr = nbr / 16;
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
