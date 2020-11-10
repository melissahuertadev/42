/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:18:20 by mhuerta           #+#    #+#             */
/*   Updated: 2020/11/10 02:15:28 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int     ptf_ptr(t_fields *fields, void *ptr){
    char    *str;
    int     len;
    
    if (!ptr){
        str = "0";
    } else {
        str = ft_utoa_hexa((unsigned int)ptr, 16);
    }
    len = ft_strlen(str);
    if(ptr == 0 && fields->precision == 0){
        pft_spaces(fields->width + 1, ' ');
        return fields->width;
    } else 
        pft_setpadding(fields, len);
    
    //printing
    if(fields->fMinus == 0){
        pft_spaces(fields->qSpaces - 1, ' ');
    }
    pft_spaces(fields->qZeros + 1, '0');
    ft_printf("0x%s", str);
    if(fields->fMinus == 1){
        pft_spaces(fields->qSpaces + 1, ' ');
    }

    return len;
}