/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:47:28 by sdanel            #+#    #+#             */
/*   Updated: 2022/12/01 12:47:30 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhexamin(unsigned int nb)
{
	char	*base;
	int		res[8];
	int		i;
	int		count;

	base = "0123456789abcdef";
	i = 0;
	count = 0;
	while (nb >= 16)
	{
		res[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	res[i] = base[nb];
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
		count++;
	}
	return (count);
}

int	ft_putnbrhexamaj(unsigned int nb)
{
	char	*base;
	int		res[8];
	int		i;
	int		count;

	base = "0123456789ABCDEF";
	i = 0;
	count = 0;
	while (nb >= 16)
	{
		res[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	res[i] = base[nb];
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
		count++;
	}
	return (count);
}

void	ft_printptr(int i, int *res)
{
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
	}
}

int	ft_putptr(void *ptr)
{
	char				*base;
	int					res[18];
	int					i;
	int					count;
	unsigned long long	int_ptr;

	int_ptr = (unsigned long long) ptr;
	base = "0123456789abcdef";
	i = 0;
	count = ft_unsignedintlen16(int_ptr);
	if (!int_ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	while (int_ptr >= 16)
	{
		res[i] = base[int_ptr % 16];
		int_ptr = int_ptr / 16;
		i++;
	}
	res[i] = ft_putstr("0x");
	res[i] = base[int_ptr];
	ft_printptr(i, res);
	return (count + 2);
}
