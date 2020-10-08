/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:54:11 by mhuerta           #+#    #+#             */
/*   Updated: 2019/08/22 14:01:57 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

//gcc -Wall -Wextra -Werror main_mem.c ft_strcpy.c

int main()
{
    const char s[50] = "42 is life";
    char d[50];

    ft_strcpy(d, "this text will be erased!");
    printf("Before memcpy = %s\n", d);
    //memcpy(d, s, strlen(s));
    ft_memcpy(d, s, strlen(s));
    printf("After memcpy = %s\n", d);
    return (0);
}