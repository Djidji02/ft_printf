/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:15:08 by snadji-h          #+#    #+#             */
/*   Updated: 2021/11/05 18:58:36 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void tester(int(*pf)(const char *, ...))
{
	pf(" %s %c !\n", "HELLO", 'A');
	pf(" %s \n", 0);
}

int main()
{
	printf("==== printf ====\n");
	tester(printf);
	printf("==== ft_printf ====\n");
	tester(ft_printf);
}	
