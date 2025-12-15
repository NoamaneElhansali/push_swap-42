/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 03:56:40 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 04:48:11 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
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
	ft_select_algo(&stack_a, &stack_b);
	free(read_para_numbres);
	free(sort_numbres);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
