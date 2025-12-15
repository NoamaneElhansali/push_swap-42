/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:59:29 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 04:49:48 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_element(t_stack *a, t_stack *b, int end_size, int total_size)
{
	t_end	sort;

	sort.end_size = end_size;
	sort.start = 0;
	sort.end = end_size;
	while (a->size > 0)
		push_element_ut(a, b, &sort, total_size);
}

void	ft_solve_element(t_stack *a, t_stack *b)
{
	int	end_size;

	end_size = get_end_size(a->size);
	push_element(a, b, end_size, a->size);
	bring_back_sorted(a, b);
}

void	bring_rank_to_top_desc(t_stack *stack, int pos)
{
	if (pos <= stack->size / 2)
		while (pos--)
			ft_rb(stack);
	else
	{
		pos = stack->size - pos;
		while (pos--)
			ft_rrb(stack);
	}
}

void	sort_three(t_stack *a)
{
	int (f), (s), (t);
	f = a->top->rank;
	s = a->top->next->rank;
	t = a->top->next->next->rank;
	if (f < s && s < t)
		return ;
	else if (f > s && s < t && f < t)
		ft_sa(a);
	else if (f < s && s > t && f < t)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (f > s && s > t && f > t)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (f < s && s > t && f > t)
		ft_rra(a);
	else if (f > s && s < t && f > t)
		ft_ra(a);
}

int	ft_atoi_u(char **nptr, int *arr, int *i)
{
	int	sign;
	int	value;

	while (**nptr)
	{
		sign = get_sign(nptr);
		if (!sign || !read_number(nptr, sign, &value))
			return (0);
		arr[(*i)++] = value;
	}
	return (1);
}
