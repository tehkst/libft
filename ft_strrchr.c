/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toniteh <toniteh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:52:07 by toniteh           #+#    #+#             */
/*   Updated: 2025/05/13 16:01:43 by toniteh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
    int		i;
    char	*ptr;

    i = ft_strlen(s);
    ptr = (char *)s;
    while (i >= 0)
    {
        if (ptr[i] == (char)c)
            return (ptr + i);
        i--;
    }
    return (0);
}