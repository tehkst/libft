/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toniteh <toniteh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:51:30 by toniteh           #+#    #+#             */
/*   Updated: 2025/05/06 12:54:03 by toniteh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t          i;
    unsigned char   *d;
    const unsigned char   *s;

    i = 0;
    d = (unsigned char *)dst;
    s = (const unsigned char *)src;
    if (!dst && !src)
        return (0);
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dst);
}