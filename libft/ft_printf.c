/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:18:14 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/13 11:11:45 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_type(va_list args, char format)
{
	int	print_len;

	print_len = 0;
	if (format == '%')
		print_len = print_len + ft_putpercent();
	else if (format == 'c')
		print_len = print_len + ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len = print_len + ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_len = print_len + ft_putptr(va_arg(args, void *));
	else if (format == 'd')
		print_len = print_len + ft_putnbr(va_arg(args, int));
	else if (format == 'i')
		print_len = print_len + ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_len = print_len + ft_putunsignednbr(va_arg(args, unsigned int));
	else if (format == 'x')
		print_len = print_len + ft_putnbrhexamin(va_arg(args, unsigned int));
	else if (format == 'X')
		print_len = print_len + ft_putnbrhexamaj(va_arg(args, unsigned int));
	else
		return (0);
	return (print_len);
}

int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;
	int		i;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len = print_len + ft_format_type(args, str[i + 1]);
			i++;
		}
		else
			print_len = print_len + ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

// int	main(void)
// 	ft_printf("size = %d\n", ft_printf("Une string (%%s) = %s\n", str1));
// 	printf("\n");
// 	printf("size = %d\n", printf("Un char (%%c) = %c\n", c));
// 	ft_printf("size = %d\n", ft_printf("Un char (%%c) = %c\n", c));
// 	printf("\n");
// 	printf("size = %d\n", printf("Un pointeur (%%p) = %p\n", &str1));
// 	ft_printf("size = %d\n", ft_printf("Un pointeur (%%p) = %p\n", &str1));
// 	printf("\n");
// 	printf("size = %d\n", printf("Un nombre (%%d) = %ld\n", -2147483648));
// 	ft_printf("size = %d\n", ft_printf("Un nombre (%%d) = %d\n", -2147483648));
// 	printf("\n");
// 	printf("size = %d\n", printf("un nombre (%%i) = %i\n", 0));
// 	ft_printf("size = %d\n", ft_printf("un nombre (%%i) = %i\n", 0));
// 	printf("\n");
// 	printf("size = %d\n", printf("Un nombre non signe (%%u) = %u\n", 0));
// 	ft_printf("size = %d\n", ft_printf("Un nombre non signe (%%u) = %u\n", 0));
// 	printf("\n");
// 	printf("size = %d\n", printf("Un hexa min (%%x) = %x\n", 123505));
// 	ft_printf("size = %d\n", ft_printf("Un hexa min (%%x) = %x\n", 123505));
// 	ft_printf("\n");
// 	printf("size = %d\n", printf("Un hexa maj (%%X) = %X\n", 123505));
// 	ft_printf("size = %d\n", ft_printf("Un hexa maj (%%X) = %X\n", 123505));
// 	ft_printf("\n");
// 	printf("size = %d\n", printf("Un pourcentage (%%%%) = %%\n"));
// 	ft_printf("size = %d\n", ft_printf("Un pourcentage (%%%%) = %%\n"));
// }