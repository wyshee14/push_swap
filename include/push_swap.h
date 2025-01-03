/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:12:04 by wshee             #+#    #+#             */
/*   Updated: 2025/01/03 18:03:30 by wshee            ###   ########.fr       */
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
	int			number;
	int			index;
	int			above_median;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_head
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_head;

//Initialize stack
void	init_stack(t_stack **stack, char **argv);

//Error handling
int is_numeric(const char *str);
int handle_duplicate(t_stack *stack, long nbr);
void free_stack(t_stack **stack);
void print_error(t_stack **stack_a);

//Sort
void	sort_three(t_stack **stack_a);
int		stack_sorted(t_stack *stack);
int	set_index(t_stack *stack, int min);
void	above_median(t_stack *stack);
void	sort_small(t_stack **stack_a, t_stack **stack_b);

//Utils
int	stack_size(t_stack *stack);
t_stack *get_last_node(t_stack *last);

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
