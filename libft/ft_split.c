/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:39:22 by nelhansa          #+#    #+#             */
/*   Updated: 2025/10/21 18:56:40 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_word(char *s, char c)
{
	int	is_word;
	int	count;

	is_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_get_word(char *start, char *end)
{
	return (ft_substr(start, 0, end - start));
}

static void	ft_free_split(char **split, int i)
{
	while (--i >= 0)
		free(split[i]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	const char	*tmp;
	char		**ptr;
	int			i;

	if (!s)
		return (NULL);
	ptr = malloc((ft_count_word((char *)s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		tmp = s;
		while (*s && *s != c)
			s++;
		if (s > tmp)
			ptr[i++] = ft_get_word((char *)tmp, (char *)s);
		if (i > 0 && !ptr[i - 1])
			return (ft_free_split(ptr, i - 1), NULL);
	}
	ptr[i] = NULL;
	return (ptr);
}
