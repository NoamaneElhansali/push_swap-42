/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:01:45 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 02:57:50 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra_rrb(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (stack->size < 2)
		return (0);
	prev = stack->top;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	return (1);
}

void	ft_rra(t_stack *stack)
{
	if (ft_rra_rrb(stack))
		ft_putstr("rra\n");
}

void	ft_rrb(t_stack *stack)
{
	if (ft_rra_rrb(stack))
		ft_putstr("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	ft_rra_rrb(a);
	ft_rra_rrb(b);
	ft_putstr("rrr\n");
}

void	ft_rrr_ch(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	ft_rra_rrb(a);
	ft_rra_rrb(b);
}
