/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:29:38 by mhuerta           #+#    #+#             */
/*   Updated: 2019/09/02 15:55:47 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Iterates a list lst and applies the function f to each link
**to create a “fresh” list (using malloc(3)) resulting from
**the successive applications of f.
**If the allocation fails, the function returns NULL.
**return value-> The new list.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (!(new = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new = f(new);
	lst = lst->next;
	tmp = new;
	while (lst)
	{
		if (!(tmp->next = ft_lstnew(lst)))
			return (NULL);
		tmp->next = f(tmp->next);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (new);
}
