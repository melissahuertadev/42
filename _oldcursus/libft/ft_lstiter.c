/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:27:47 by mhuerta           #+#    #+#             */
/*   Updated: 2019/09/02 09:42:16 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Iterates the list lst and applies the function f to each link.
**return value-> None.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
