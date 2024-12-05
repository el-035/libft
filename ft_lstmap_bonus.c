/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:11:48 by efittant          #+#    #+#             */
/*   Updated: 2024/09/24 17:11:49 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	while (lst->next)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstiter(new, ft_lstdelone(new, del));
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = new;
		lst->next = lst;
	}
	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		ft_lstiter(new, ft_lstdelone(new, del));
		return (NULL);
	}
	new->content = f(lst->content);
	return (new);
}

/*lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
del: The address of the function used to delete
the content of a node if needed.
The new list.
NULL if the allocation fails.
malloc, free
Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/
