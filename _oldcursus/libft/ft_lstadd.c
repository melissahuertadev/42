/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:31:35 by mhuerta           #+#    #+#             */
/*   Updated: 2019/09/02 09:38:16 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Adds the element new at the beginning of the list.
**Param. #1: The address of a pointer to the first link of a list.
**Param. #2: The link to add at the beginning of the list.
**return value-> none.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = (*alst);
		(*alst) = new;
	}
}
