/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:03:01 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/14 22:53:19 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa_sb(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	return (1);
}

void	ft_sa(t_stack *stack)
{
	if (ft_sa_sb(stack))
		ft_putstr("sa\n");
}

void	ft_sb(t_stack *stack)
{
	if (ft_sa_sb(stack))
		ft_putstr("sb\n");
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 && stack_b->size < 2)
		return ;
	ft_sa_sb(stack_a);
	ft_sa_sb(stack_b);
}
