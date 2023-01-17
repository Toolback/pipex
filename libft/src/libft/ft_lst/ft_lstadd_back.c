/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:44:29 by jurenaul          #+#    #+#             */
/*   Updated: 2022/10/15 13:38:34 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Adds the element ’new’ at the end of the list.
*	PARAMETERS
*	#1. The address of a pointer to the first link of a list.
*	#2. The address of a pointer to the element to be added to the list.
*	RETURN VALUES
*	-
*/

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (new)
	{
		if (!*alst)
		{
			*alst = new;
			return ;
		}
		temp = ft_lstlast(*alst);
		temp->next = new;
	}
}
