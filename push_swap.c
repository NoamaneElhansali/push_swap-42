/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:19:17 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 03:56:53 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_atoi_str(char **argv, int count_numbres)
{
	int	*arr_numbres;
	int	i;

	arr_numbres = malloc(count_numbres * sizeof(int));
	if (!arr_numbres)
		return (NULL);
	i = 0;
	while (*argv)
	{
		if (**argv == '\0' || !ft_atoi_u(argv, arr_numbres, &i))
			return (free(arr_numbres), NULL);
		argv++;
	}
	return (arr_numbres);
}

int	*ft_read_para(char **argv)
{
	int	count_numbres;
	int	*numbres;

	count_numbres = ft_count_numbres(argv);
	if (count_numbres < 0)
		return (NULL);
	numbres = ft_atoi_str(argv, count_numbres);
	if (!numbres)
		return (NULL);
	if (ft_check_is_dup_numbres(numbres, count_numbres))
		return (free(numbres), NULL);
	return (numbres);
}

void	ft_select_algo(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		return ;
	if (a->size == 2)
		return (ft_sa(a));
	if (a->size == 3)
		return (sort_three(a));
	else
		ft_solve_element(a, b);
}
