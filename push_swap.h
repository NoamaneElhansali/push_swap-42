/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:34:52 by nelhansa          #+#    #+#             */
/*   Updated: 2025/12/15 14:38:27 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_end
{
	int				start;
	int				end;
	int				end_size;
}					t_end;

int					*ft_read_para(char **argv);
int					*ft_atoi_str(char **argv, int count_numbres);
int					ft_check_is_dup_numbres(int *numbres, int size);
int					*ft_numbre_dup(int *src, int size);
int					*ft_pre_sort(int *numbres, int size);
t_node				*ft_create_node(int value, int rank);
t_node				*ft_last_node(t_stack *stack);
void				ft_append_node(t_stack *stack, t_node *new);
int					ft_numbre_rank(int numbre, int *sort_numbres, int size);
int					ft_show_error(char *str);
t_stack				ft_store_numbres_stack(int *numbres, int *sort_numbres,
						int size);
int					ft_check_is_sorted(int *numbres, int size);
int					ft_rra_rrb(t_stack *stack);
void				ft_rra(t_stack *stack);
void				ft_rrb(t_stack *stack);
void				ft_rrr(t_stack *a, t_stack *b);
void				ft_rrr_ch(t_stack *a, t_stack *b);
int					ft_ra_rb(t_stack *stack);
void				ft_ra(t_stack *stack);
void				ft_rb(t_stack *stack);
void				ft_rr(t_stack *a, t_stack *b);
void				ft_rr_ch(t_stack *a, t_stack *b);
int					ft_pa_pb(t_stack *from, t_stack *to);
void				ft_pa(t_stack *from, t_stack *to);
void				ft_pb(t_stack *from, t_stack *to);
int					ft_sa_sb(t_stack *stack);
void				ft_sa(t_stack *stack);
void				ft_sb(t_stack *stack);
void				ft_ss(t_stack *stack_a, t_stack *stack_b);
void				bring_back_sorted(t_stack *a, t_stack *b);
void				ft_putstr(char *s);
void				ft_free_stack(t_stack *stack);
void				ft_select_algo(t_stack *a, t_stack *b);
void				sort_three(t_stack *a);
void				ft_solve_element(t_stack *a, t_stack *b);
void				push_element(t_stack *a, t_stack *b, int end_size,
						int total_size);
void				push_element_ut(t_stack *a, t_stack *b, t_end *sort,
						int total_size);
int					get_end_size(int total);
void				bring_rank_to_top_desc(t_stack *stack, int pos);
int					find_rank_pos(t_stack *stack, int rank);
int					find_max_rank(t_stack *stack);
int					ft_count_check(char *s, int *count);
int					ft_atoi_u(char **nptr, int *arr_numbres, int *i);
int					get_sign(char **s);
int					read_number(char **s, int sign, int *out);
int					ft_count_numbres(char **argv);

#endif