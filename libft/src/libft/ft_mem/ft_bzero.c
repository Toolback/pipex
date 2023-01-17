/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:24:46 by jurenaul          #+#    #+#             */
/*   Updated: 2022/10/11 22:25:59 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*	The bzero() function writes n zeroed bytes to the string s.  
*   If n is zero, bzero() does nothing.
*	PARAMETERS
*	#1. The pointer from which to begin erasing data.
*	#2. The number of bytes to erase.
*	RETURN VALUES
*	- 
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*str_c;

	str_c = (char *)s;
	i = 0;
	while (i < n)
	{
		*(str_c + i) = 0;
		i++;
	}
}
