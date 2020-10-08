/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:03:22 by mhuerta           #+#    #+#             */
/*   Updated: 2019/08/25 19:50:39 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

//gcc -Wall -Wextra -Werror main_memmove.c ft_strcpy.c ft_memmove.c ft_memcpy.c ft_strlen.c

int main()
{
    const char s[50] = "42 is life";
    char d[30];

    ft_strcpy(d, "this text will be erased!");
    printf("Before memcpy = %s\n", d);
    memmove(d, s, strlen(s));
    printf("After memcpy = %s\n", d);
    ft_memmove(d, s, strlen(s));
    printf("After ft_memcpy = %s\n", d);
    return (0);
}
