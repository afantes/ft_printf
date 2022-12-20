/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:46:14 by afantes           #+#    #+#             */
/*   Updated: 2022/11/25 22:58:11 by afantes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(char c, va_list vf, int *l)
{
	if (c == '%')
		(*l) += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		(*l) += ft_putnbr(va_arg(vf, int));
	else if (c == 'c')
		(*l) += ft_putchar(va_arg(vf, int));
	else if (c == 's')
		(*l) += ft_putstr(va_arg(vf, char *));
	else if (c == 'x')
		(*l) += ft_hexadecimal(va_arg(vf, unsigned int), 1);
	else if (c == 'X')
		(*l) += ft_hexadecimal(va_arg(vf, unsigned int), 0);
	else if (c == 'p')
	{
		ft_putstr("0x");
		(*l) += 2;
		(*l) += ft_hexadecimal(va_arg(vf, unsigned long), 1);
	}
	else if (c == 'u')
		(*l) += ft_unsigned_int(va_arg(vf, unsigned int));
}

int	ft_printf(const char *s, ...)
{
	int		l;
	int		i;
	va_list	vf;

	l = 0;
	i = 0;
	va_start(vf, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				return (i);
			print(s[i], vf, &l);
		}
		else
		{
			ft_putchar(s[i]);
			l++;
		}
		i++;
	}
	va_end(vf);
	return (l);
}
