/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:14:08 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/14 22:36:56 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa_pb(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (from->size == 0)
		return (0);
	tmp = from->top;
	from->top = tmp->next;
	from->size--;
	tmp->next = to->top;
	to->top = tmp;
	to->size++;
	return (1);
}

void	ft_pa(t_stack *from, t_stack *to)
{
	if (ft_pa_pb(from, to))
		ft_putstr("pa\n");
}

void	ft_pb(t_stack *from, t_stack *to)
{
	if (ft_pa_pb(from, to))
		ft_putstr("pb\n");
}
