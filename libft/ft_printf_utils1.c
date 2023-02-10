/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:56:16 by sdanel            #+#    #+#             */
/*   Updated: 2022/12/01 12:48:06 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrlen(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb == -2147483648)
	{
		i = i + 2;
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = ft_putnbrlen(nb);
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
	return (count);
}

int	ft_unsignedintlen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_unsignedintlen16(unsigned long long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_putunsignednbr(unsigned int nb)
{
	int	count;

	count = ft_unsignedintlen(nb);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
	return (count);
}
