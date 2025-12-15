/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:23:48 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 04:51:22 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra_rb(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return (0);
	first = stack->top;
	stack->top = first->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ft_ra(t_stack *stack)
{
	if (ft_ra_rb(stack))
		ft_putstr("ra\n");
}

void	ft_rb(t_stack *stack)
{
	if (ft_ra_rb(stack))
		ft_putstr("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	if (ft_ra_rb(a) && ft_ra_rb(b))
		ft_putstr("rr\n");
}

void	ft_rr_ch(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	ft_ra_rb(a);
	ft_ra_rb(b);
}
