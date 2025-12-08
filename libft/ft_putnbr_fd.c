/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:30:05 by nelhansa          #+#    #+#             */
/*   Updated: 2025/10/20 19:33:01 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_numlen(long int a)
{
	int	len;

	len = (a <= 0);
	if (a < 0)
		a = -a;
	while (a > 0)
	{
		a /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	int			len;
	long int	c;
	char		num[15];

	c = n;
	len = ft_numlen(c);
	num[len--] = '\0';
	if (c < 0)
	{
		num[0] = '-';
		c = -c;
	}
	if (c == 0)
		num[len--] = '0';
	while (c > 0)
	{
		num[len--] = (c % 10) + 48;
		c /= 10;
	}
	len = 0;
	while (num[len])
	{
		write(fd, &num[len++], 1);
	}
}
