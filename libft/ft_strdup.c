/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:07:01 by nelhansa          #+#    #+#             */
/*   Updated: 2025/10/21 17:47:26 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	int (len_s), (i);
	len_s = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	str = malloc((len_s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len_s)
	{
		*(str + i) = *(s + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
