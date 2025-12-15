/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:11:05 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 04:05:35 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "get_next_line.h"
# include "push_swap.h"

int		ft_strcmp(const char *s1, const char *s2);
int		check_opr_valid(char *str, t_stack *a, t_stack *b);
int		check_is_sorted(t_stack *a, t_stack *b);
void	ft_excute_opr(t_stack *a, t_stack *b);

#endif