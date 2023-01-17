/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:15:08 by jurenaul          #+#    #+#             */
/*   Updated: 2022/10/11 23:37:06 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <ctype.h>
*	DESCRIPTION
*	The tolower() function converts an upper-case letter to the corresponding 
*	lower-case letter.  The argument must be representable as an unsigned char 
*	or the value of EOF.
*	PARAMETERS
*	#1. The character to convert.
*	RETURN VALUES
*	If the argument is an upper-case letter, the tolower() function returns the 
*	corresponding lower-case letter if there is one; otherwise, the argument 
*	is returned unchanged.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
