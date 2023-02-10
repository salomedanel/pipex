/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:26:45 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/30 16:26:46 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_format_type(va_list args, char format);
int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbrlen(int nb);
int		ft_putnbr(int nb);
int		ft_unsignedintlen(unsigned int nb);
int		ft_unsignedintlen16(unsigned long long nb);
int		ft_putunsignednbr(unsigned int nb);
int		ft_putpercent(void);
int		ft_putnbrhexamin(unsigned int nb);
int		ft_putnbrhexamaj(unsigned int nb);
void	ft_printptr(int i, int *res);
int		ft_putptr(void *ptr);

#endif