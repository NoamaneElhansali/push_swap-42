/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:17:52 by nelhansa          #+#    #+#             */
/*   Updated: 2025/10/21 19:00:47 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big || !little)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (*(big + i) && i < len)
	{
		j = 0;
		while (*(little + j) && (i + j) < len
			&& *(big + i + j) == *(little + j))
			j++;
		if (*(little + j) == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
