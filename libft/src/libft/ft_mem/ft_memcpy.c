/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:00:00 by jurenaul          #+#    #+#             */
/*   Updated: 2022/10/11 23:52:19 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*   The  memcpy()  function  copies  n bytes from memory area src to memory
*   area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
*   memory areas do overlap.
*	PARAMETERS
*	#1. The first string to copy from.
*	#2. The second string to copy to.
*	#3. The number of bytes to to copy.
*	RETURN VALUES
*   The memcpy() function returns a pointer to dest.

*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
