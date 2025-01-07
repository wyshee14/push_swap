/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:12:04 by wshee             #+#    #+#             */
/*   Updated: 2025/01/07 18:14:29 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//init_stack.c
void	init_stack(t_stack **stack, char **argv);

//error_handling.c
int is_numeric(const char *str);
int handle_duplicate(t_stack *stack, long nbr);
void free_stack(t_stack **stack);
void print_error(t_stack **stack_a);

//pre_sort.c
int partition(int *arr, int low, int high);
void quicksort(int *arr, int low, int high);
void init_array(int *arr, t_stack *stack);
int set_index_to_stack(int *arr,int low, int high, int key);
void pre_sort(t_stack **stack_a);

//sort_small.c
t_stack *find_max(t_stack *stack);
t_stack *find_min(t_stack *stack);
void	sort_three(t_stack **stack_a);
void	sort_small(t_stack **stack_a, t_stack **stack_b);

//sort_big.c
void	sort_big(t_stack **stack_a, t_stack **stack_b);

//stack_utils.c
int	stack_size(t_stack *stack);
int stack_sorted(t_stack *stack);
t_stack *get_last_node(t_stack *last);
int set_index(t_stack *stack, int target);
void ft_swap(int *i, int *j);

//Operations
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

#endif
