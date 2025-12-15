/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:57:07 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/14 22:52:36 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_create_node(int value, int rank)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->rank = rank;
	new->next = NULL;
	return (new);
}

t_node	*ft_last_node(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_append_node(t_stack *stack, t_node *new)
{
	t_node	*tmp;

	if (!stack->top)
	{
		stack->top = new;
		new->next = NULL;
		return ;
	}
	tmp = ft_last_node(stack);
	tmp->next = new;
	new->next = NULL;
}

t_stack	ft_store_numbres_stack(int *numbres, int *sort_numbres, int size)
{
	int		i;
	int		rank;
	t_stack	stack;
	t_node	*new;

	i = 0;
	stack.size = 0;
	stack.top = NULL;
	while (i < size)
	{
		rank = ft_numbre_rank(numbres[i], sort_numbres, size);
		new = ft_create_node(numbres[i], rank);
		ft_append_node(&stack, new);
		stack.size++;
		i++;
	}
	return (stack);
}
