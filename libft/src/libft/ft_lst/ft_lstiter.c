/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:21:31 by jurenaul          #+#    #+#             */
/*   Updated: 2022/10/15 13:23:52 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Iterates the list ’lst’ and applies the function ’f’ to the content of each 
*	element.
*	PARAMETERS
*	#1. The adress of a pointer to an element.
*	#2. The adress of the function used to iterate on the list.
*	RETURN VALUES
*	-
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
