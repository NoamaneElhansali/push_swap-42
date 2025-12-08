/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:31:38 by nelhansa          #+#    #+#             */
/*   Updated: 2025/10/19 17:43:39 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*end;

	end = s;
	if (!s)
		return (NULL);
	while (*end)
		end++;
	while (end != s)
	{
		if (*end == (unsigned char)c)
			return ((char *)end);
		end--;
	}
	if (*end == (unsigned char)c)
		return ((char *)end);
	return (NULL);
}
