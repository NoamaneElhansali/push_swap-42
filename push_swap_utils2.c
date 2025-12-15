/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:12:05 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 04:49:11 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_is_sorted(int *numbres, int size)
{
	int (i), (j);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbres[i] > numbres[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*next;

	tmp = stack->top;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	stack->top = NULL;
	stack->size = 0;
}

int	ft_count_check(char *s, int *count)
{
	while (*s)
	{
		while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
			s++;
		if (*s == '+' || *s == '-')
		{
			if (!(*(s + 1) >= '0' && *(s + 1) <= '9'))
				return (-1);
			s++;
		}
		if (*s >= '0' && *s <= '9')
		{
			(*count)++;
			while (*s >= '0' && *s <= '9')
				s++;
		}
		else if (*s)
			return (-1);
	}
	return (1);
}

int	ft_count_numbres(char **argv)
{
	int		count;
	char	*s;

	count = 0;
	while (*argv)
	{
		s = *argv;
		if (ft_count_check(s, &count) == -1)
			return (-1);
		argv++;
	}
	return (count);
}
