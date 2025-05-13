/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toniteh <toniteh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:33:03 by toniteh           #+#    #+#             */
/*   Updated: 2025/05/13 17:52:00 by toniteh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int count_words(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char *word_dup(const char *s, size_t len)
{
	char *word;
	size_t i;

	i = 0;
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_free_split(char **split, size_t j)
{
	while (j > 0)
	{
		j--;
		free(split[j]);
	}
	free(split);
}

char **ft_split(char const *s, char c)
{
	char **result;
	size_t i;
	size_t j;
	size_t start;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			result[j] = word_dup(s + start, i - start);
			if (!result[j])
			{
				ft_free_split(result, j);
				return (0);
			}
			j++;
		}
	}
	result[j] = 0;
	return (result);
}