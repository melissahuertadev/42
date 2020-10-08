/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:30:01 by mhuerta           #+#    #+#             */
/*   Updated: 2019/09/02 09:21:31 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Allocates (with malloc(3)) and returns a “fresh” link.
**The variables content and content_size of the new link are initialized
**by copy of the parameters of the function.
**If the parameter content is nul, the variable content is initialized
**to NULL and the variable content_size is initialized to 0
**even if the parameter content_size isn’t.
**The variable next is initialized to NULL.
**If the allocation fails, the function returns NULL.
**return value-> the new link.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlst;

	if (!(nlst = (t_list *)malloc(sizeof(*nlst))))
		return (NULL);
	if (!content)
	{
		nlst->content = NULL;
		nlst->content_size = 0;
	}
	else
	{
		if (!(nlst->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(nlst->content, content, content_size);
		nlst->content_size = content_size;
	}
	nlst->next = NULL;
	return (nlst);
}
