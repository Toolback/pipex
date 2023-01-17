/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:08:55 by jurenaul          #+#    #+#             */
/*   Updated: 2022/10/11 13:35:46 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*	strlcat() appends string src to the end of dst.  It will append at most 
*	dest_size - strlen(dst) - 1 characters.  It will then NUL-terminate, unless 
*	dest_size is 0 or the original dst string was longer than dest_size 
*    (in practice this should not happen as it means  
*	that either dest_size is incorrect or that dst is not a proper string).
*	PARAMETERS
*	#1. The destiny string in which to concatenate.
*	#2. The source string to concatenate.
*	#3. The total number of bytes in destiny.
*	RETURN VALUES
*	the strlcat() function returns the length of the string it tried to create.
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	c;
	size_t	d;

	if (dest_size <= ft_strlen(dest))
		return (dest_size + ft_strlen(src));
	c = ft_strlen(dest);
	d = 0;
	while (src[d] != 0 && c + 1 < dest_size)
	{
		dest[c] = src[d];
		c++;
		d++;
	}
	dest[c] = 0;
	return (ft_strlen(dest) + ft_strlen(&src[d]));
}
