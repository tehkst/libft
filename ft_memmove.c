/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toniteh <toniteh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:51:34 by toniteh           #+#    #+#             */
/*   Updated: 2025/05/13 15:46:54 by toniteh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
    size_t              i;

    i = 0;
    if (!dst && !src)
        return (0);
    if (dst < src)
    {
        i = 0;
        while (i < len)
        {
            ((char *)dst)[i] = ((char *)src)[i];
            i++;
        } 
    }
    else
    {
        i = len;
        while (i > 0)
        {
            i--;
            ((char *)dst)[i] = ((char *)src)[i];
        }
    }
    return (dst);
}