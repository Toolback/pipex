/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:57:05 by jurenaul          #+#    #+#             */
/*   Updated: 2022/11/12 15:52:42 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int num)
{
	char	*res;
	int		len;

	len = ft_num_len(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (num != 0)
	{
		res[len - 1] = num % 10 + 48;
		num = num / 10;
		len--;
	}
	return (res);
}

int	ft_print_unsigned(unsigned int num)
{
	int		len;
	char	*res;

	len = 0;
	if (num == 0)
		len += write(1, "0", 1);
	else
	{
		res = ft_uitoa(num);
		len = ft_print_str(res);
		free(res);
	}
	return (len);
}
