/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_ut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:04:47 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 02:27:32 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_sign(char **s)
{
	int	sign;

	sign = 1;
	while ((**s >= '\t' && **s <= '\r') || **s == ' ')
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	if (**s == '-' || **s == '+')
		return (0);
	return (sign);
}

int	read_number(char **s, int sign, int *out)
{
	long	n;

	n = 0;
	if (!(**s >= '0' && **s <= '9'))
		return (0);
	while (**s >= '0' && **s <= '9')
	{
		n = n * 10 + (**s - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		(*s)++;
	}
	*out = n * sign;
	return (1);
}
