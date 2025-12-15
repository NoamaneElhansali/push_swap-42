/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:03:18 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 04:43:06 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_opr_valid(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp("sa\n", str))
		return (ft_sa_sb(a), 1);
	else if (ft_strcmp("sb\n", str))
		return (ft_sa_sb(b), 1);
	else if (ft_strcmp("ss\n", str))
		return (ft_ss(a, b), 1);
	else if (ft_strcmp("pa\n", str))
		return (ft_pa_pb(b, a), 1);
	else if (ft_strcmp("pb\n", str))
		return (ft_pa_pb(a, b), 1);
	else if (ft_strcmp("ra\n", str))
		return (ft_ra_rb(a), 1);
	else if (ft_strcmp("rb\n", str))
		return (ft_ra_rb(b), 1);
	else if (ft_strcmp("rr\n", str))
		return (ft_rr_ch(a, b), 1);
	else if (ft_strcmp("rra\n", str))
		return (ft_rra_rrb(a), 1);
	else if (ft_strcmp("rrb\n", str))
		return (ft_rra_rrb(b), 1);
	else if (ft_strcmp("rrr\n", str))
		return (ft_rrr(a, b), 1);
	else
		return (0);
}

int	check_is_sorted(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->size > 0)
		return (0);
	tmp = a->top;
	while (tmp->next)
	{
		if (tmp->rank > tmp->next->rank)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_excute_opr(t_stack *a, t_stack *b)
{
	char	*opr;

	while (1)
	{
		opr = get_next_line(0);
		if (!opr)
			break ;
		if (!check_opr_valid(opr, a, b))
			return (free(opr), (void)ft_show_error("Error\n"));
		free(opr);
	}
	if (check_is_sorted(a, b))
		return (ft_putstr("OK"));
	else
		return (ft_putstr("KO"));
}

int	main(int argc, char **argv)
{
	int		count_numbre;
	t_stack	stack_a;
	t_stack	stack_b;
	int		*sort_numbres;
	int		*read_para_numbres;

	if (argc < 2)
		return (0);
	count_numbre = ft_count_numbres(argv + 1);
	read_para_numbres = ft_read_para(argv + 1);
	if (!read_para_numbres)
		return (ft_show_error("Error\n"));
	if (ft_check_is_sorted(read_para_numbres, count_numbre))
		return (free(read_para_numbres), 0);
	sort_numbres = ft_pre_sort(read_para_numbres, count_numbre);
	stack_a = ft_store_numbres_stack(read_para_numbres, sort_numbres,
			count_numbre);
	stack_b.size = 0;
	stack_b.top = NULL;
	ft_excute_opr(&stack_a, &stack_b);
	free(read_para_numbres);
	free(sort_numbres);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
