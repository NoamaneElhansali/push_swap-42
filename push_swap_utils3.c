/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:57:59 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/14 22:42:44 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_rank(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	tmp = stack->top;
	max = -1;
	while (tmp)
	{
		if (tmp->rank > max)
			max = tmp->rank;
		tmp = tmp->next;
	}
	return (max);
}

int	find_rank_pos(t_stack *stack, int rank)
{
	t_node	*tmp;
	int		pos;

	tmp = stack->top;
	pos = 0;
	while (tmp)
	{
		if (tmp->rank == rank)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

int	get_end_size(int total)
{
	if (total <= 100)
		return (total / 6);
	else
		return (total / 14);
}

void	push_element_ut(t_stack *a, t_stack *b, t_end *sort, int total_size)
{
	if (!a->top)
		return ;
	if (a->top->rank <= sort->start)
	{
		ft_pb(a, b);
		ft_rb(b);
		sort->start++;
		if (sort->end < total_size - 1)
			sort->end++;
	}
	else if (a->top->rank <= sort->end)
	{
		ft_pb(a, b);
		if (b->size > 1 && b->top->next && b->top->next->rank > b->top->rank)
			ft_sb(b);
		sort->start++;
		if (sort->end < total_size - 1)
			sort->end++;
	}
	else
		ft_ra(a);
}

void	bring_back_sorted(t_stack *a, t_stack *b)
{
	int	max_rank;
	int	pos;

	while (b->size > 0)
	{
		max_rank = find_max_rank(b);
		pos = find_rank_pos(b, max_rank);
		bring_rank_to_top_desc(b, pos);
		ft_pa(b, a);
	}
}
