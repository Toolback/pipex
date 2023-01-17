/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:37:56 by jurenaul          #+#    #+#             */
/*   Updated: 2022/11/12 15:52:48 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(va_list args, const char c)
{
	int	print_length;

	print_length = 0;
	if (c == 'c')
		print_length += ft_print_char(va_arg(args, int));
	else if (c == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		print_length += ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		print_length += ft_print_percent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
