/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:17:07 by snadji-h          #+#    #+#             */
/*   Updated: 2021/11/12 15:22:07 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef char	t_bool;

typedef struct s_flags
{
	t_bool	neg;
	t_bool	pos;
	t_bool	space;
	t_bool	hash;
	t_bool	zero;

}	t_flags;

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printf(const char *fmt, ...);
int	ft_hex(unsigned int nbr, char *base, t_flags flags);
int	ft_hex_ptr(void *ptr, char *base);
int	ft_udec(unsigned int nbr, char *base, t_flags flags);
int	ft_dec(int nbr, char *base, t_flags flags);

#endif
