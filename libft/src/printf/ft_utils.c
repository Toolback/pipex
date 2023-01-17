/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:37:22 by jurenaul          #+#    #+#             */
/*   Updated: 2022/11/12 15:52:53 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int num)
{
	int		len;
	char	*res;

	len = 0;
	res = ft_itoa(num);
	len = ft_print_str(res);
	free(res);
	return (len);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
