/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:59:25 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/08 09:57:34 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_atoi(const char *nptr)
{
	int (numbre), (positive);
	numbre = 0;
	positive = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			positive = -positive;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		numbre = (numbre * 10) + (*nptr - 48);
		nptr++;
	}
	return (numbre * positive);
}
