/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:37:39 by wshee             #+#    #+#             */
/*   Updated: 2025/01/13 15:55:45 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;
	long	max;

	if (!stack)
		return (NULL);
	max = stack->number;
	max_node = stack;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack-> next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	long	min;

	if (!stack)
		return (NULL);
	min = stack->number;
	min_node = stack;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack-> next;
	}
	return (min_node);
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*max_node;

	max_node = find_max(*stack_a);
	if ((*stack_a) == max_node)
		ra(stack_a, 1);
	else if ((*stack_a)->next == max_node)
		rra(stack_a, 1);
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a, 1);
}

//push the minimum number to stack b
//find the minimum in stack a (set as target)
//find the position of minimum in stack a
//if position above median ra, else rra, until the target is at the top of stack
//push to stack b(pb) until left 3 in stack a (in loop)
static void	get_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_node;
	int		target;
	int		i;
	int		median;

	i = 0;
	while (stack_size(*stack_a) > 3)
	{
		min_node = find_min(*stack_a);
		target = min_node->number;
		i = set_index(*stack_a, target, 'a');
		median = stack_size(*stack_a) / 2;
		while ((*stack_a)->number != target)
		{
			if (i < median)
				ra(stack_a, 1);
			else
				rra(stack_a, 1);
		}
		pb(stack_b, stack_a, 1);
	}
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) <= 3)
		sort_three(stack_a);
	else
	{
		get_three(stack_a, stack_b);
		sort_three(stack_a);
		while (*stack_b != NULL)
			pa(stack_a, stack_b, 1);
	}
}
