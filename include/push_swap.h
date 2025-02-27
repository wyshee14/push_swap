/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:12:04 by wshee             #+#    #+#             */
/*   Updated: 2025/01/14 16:19:18 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//push_swap.c
char	*str_join(char **av);
char	**get_input(int ac, char **av);
void	do_sort(t_stack **stack_a, t_stack **stack_b);

//init_stack.c
void	init_stack(t_stack **stack, char **argv);
void	free_2d(char **av);

//error_handling.c
int		is_numeric(const char *str);
int		handle_duplicate(t_stack *stack, long nbr);
void	free_stack(t_stack **stack);
void	print_error(t_stack **stack_a, char **input);

//pre_sort.c
int		partition(int *arr, int low, int high);
void	quicksort(int *arr, int low, int high);
void	init_array(int *arr, t_stack *stack);
int		set_index_to_stack(int *arr, int low, int high, int key);
void	pre_sort(t_stack **stack_a);

//sort_small.c
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	sort_three(t_stack **stack_a);
void	sort_small(t_stack **stack_a, t_stack **stack_b);

//sort_big.c
void	sort_big(t_stack **stack_a, t_stack **stack_b);

//stack_utils.c
int		stack_size(t_stack *stack);
int		stack_sorted(t_stack *stack);
t_stack	*get_last_node(t_stack *last);
int		set_index(t_stack *stack, int target, char stack_type);
void	ft_swap(int *i, int *j);

//Operations
void	pa(t_stack **stack_a, t_stack **stack_b, int checker);
void	pb(t_stack **stack_b, t_stack **stack_a, int checker);
void	rra(t_stack **stack_a, int checker);
void	rrb(t_stack **stack_b, int checker);
void	rrr(t_stack **stack_a, t_stack **stack_b, int checker);
void	ra(t_stack **stack_a, int checker);
void	rb(t_stack **stack_b, int checker);
void	rr(t_stack **stack_a, t_stack **stack_b, int checker);
void	sa(t_stack **stack_a, int checker);
void	sb(t_stack **stack_b, int checker);
void	ss(t_stack **stack_a, t_stack **stack_b, int checker);

#endif
