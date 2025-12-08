/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:56:43 by nelhansa          #+#    #+#             */
/*   Updated: 2025/10/21 19:01:58 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_dst = 0;
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	len_src = 0;
	while (src[len_src])
		len_src++;
	if (size == len_dst)
		return (len_src + size);
	i = 0;
	while (src[i] && len_dst + i + 1 < size)
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	if (len_dst + i < size)
		dst[i + len_dst] = '\0';
	return (len_dst + len_src);
}
