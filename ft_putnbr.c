/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:46:52 by afantes           #+#    #+#             */
/*   Updated: 2022/11/15 23:25:13 by afantes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		len += (ft_putstr("-214748364"));
		nb = 8;
	}
	if (nb < 0)
	{
		len += (ft_putchar('-'));
		nb = -nb;
	}
	if (nb > 9)
	{
		len += (ft_putnbr(nb / 10));
		len += (ft_putnbr(nb % 10));
	}
	else
		len += (ft_putchar(nb + 48));
	return (len);
}
