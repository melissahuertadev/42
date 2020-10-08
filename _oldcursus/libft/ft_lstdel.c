/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:23:23 by mhuerta           #+#    #+#             */
/*   Updated: 2019/09/02 09:41:09 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Takes as a parameter the adress of a pointer to a link
**and frees the memory of this link and every successors of that link
**using the functions del and free(3).
**NOTE: function del is a input parameter!
**Finally the pointer to the link that was just freed must be set to NULL
**(quite similar to the function ft_memdel from the mandatory part).
**return value-> None.
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (!*alst || !alst)
		return ;
	while (*alst)
	{
		next = (*alst)->next;
		del((*aslt)->content, (*alst)->content_size);
		free(*alst);
		*alst = next;
	}
}
