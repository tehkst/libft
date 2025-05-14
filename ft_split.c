/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toniteh <toniteh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:33:03 by toniteh           #+#    #+#             */
/*   Updated: 2025/05/14 22:45:22 by toniteh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_sep(char c, char sep)
{
	return (c == sep);
}

char *copy_word(const char *start, const char *end)
{
	char *word;
	size_t len;

	len = end - start;
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

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
	size_t *start;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (0);
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s)
		{
			start = s;
			while (*s && !is_sep(*s, c))
				s++;
			result[i] = copy_word(start, s);
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}