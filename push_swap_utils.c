/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:52:19 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 04:50:25 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_is_dup_numbres(int *numbres, int size)
{
	int (i), (j);
	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbres[i] == numbres[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_numbre_dup(int *src, int size)
{
	int	*copy;
	int	i;

	i = 0;
	copy = malloc(size * sizeof(int));
	while (i < size)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}

int	*ft_pre_sort(int *numbres, int size)
{
	int	*copy;

	int (i), (j), (tmp);
	if (size <= 0)
		return (NULL);
	copy = ft_numbre_dup(numbres, size);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (copy[i] > copy[j])
			{
				tmp = copy[i];
				copy[i] = copy[j];
				copy[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (copy);
}

int	ft_numbre_rank(int numbre, int *sort_numbres, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sort_numbres[i] == numbre)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_show_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (write(2, str, i), -1);
}
