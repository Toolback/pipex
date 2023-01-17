/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:24:05 by jurenaul          #+#    #+#             */
/*   Updated: 2022/10/15 13:29:10 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Iterates over the list lst and applies the function f to the
*   content of each element. Create a new list
*   resulting from the successive applications of f. The
*   function del is there to destroy the content of an element
*   element if necessary.
*	PARAMETERS
*	#1. The address of a pointer to the first link of a list.
*	#2. The address of a function to run.
*	#3. The address of a del function
*	RETURN VALUES
*	- New List Address
*   - NULL if malloc failed
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	aux = new;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		aux->next = temp;
		aux = temp;
		lst = lst->next;
	}
	return (new);
}
