/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:16:41 by jurenaul          #+#    #+#             */
/*   Updated: 2022/10/11 22:16:49 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Outputs the string ’s’ to the given file descriptor.
*	PARAMETERS
*	#1. The string to output.
*	#2. The file descriptor on which to write.
*	RETURN VALUES
*	-
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != 0)
	{	
		while (s[i])
		{	
			write(fd, &s[i], 1);
			i++;
		}
	}
}
