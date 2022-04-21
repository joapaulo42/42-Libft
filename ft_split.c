/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapaulo <joapaulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:06:29 by joapaulo          #+#    #+#             */
/*   Updated: 2022/04/07 23:49:36 by joapaulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_strings(const char *s, char c, char **split, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && j < size)
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			split[j][k++] = s[i++];
		split[j][k] = '\0';
		j++;
	}
	k = 0;
	split[j] = NULL;
}

static void	ft_malloc_strings(const char *s, char c, char **split, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	str_size;

	i = 0;
	j = 0;
	str_size = 0;
	while (s[i] && j < size)
	{
		str_size = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i++] != c)
			str_size++;
		split[j] = malloc(sizeof(char) * (str_size + 1));
		if (split[j] == NULL)
		{
			split = NULL;
			break ;
		}
		j++;
	}
}

static int	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	str_count;

	i = 0;
	str_count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			j++;
			i++;
		}
		if (j > 0)
			str_count += j / j;
	}
	return (str_count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	str_count;

	if (!s)
		return (NULL);
	str_count = ft_count_words(s, c);
	split = malloc(sizeof(char *) * (str_count + 1));
	if (split == NULL)
		return (NULL);
	ft_malloc_strings(s, c, split, str_count);
	if (split == NULL)
		return (NULL);
	ft_fill_strings(s, c, split, str_count);
	return (split);
}
