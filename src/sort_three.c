/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:37:39 by wshee             #+#    #+#             */
/*   Updated: 2025/01/02 22:50:26 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *find_max(t_stack *stack)
{
	t_stack *max_node;
	long	max;

	if(!stack)
		return (NULL);
	max = stack->number;
	max_node = stack;
	while(stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack-> next;
	}
	// printf("max: %ld\n", max);
	// printf("max node: %d\n", max_node->number);
	return (max_node);
}

t_stack *find_min(t_stack *stack)
{
	t_stack *min_node;
	long	min;

	if(!stack)
		return (NULL);
	min = stack->number;
	min_node = stack;
	while(stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack-> next;
	}
	// printf("min: %ld\n", min);
	// printf("min node: %d\n", min_node->number);
	return (min_node);
}

void	sort_three(t_stack **stack_a)
{
	t_stack *max_node;

	max_node = find_max(*stack_a);
	//printf("max node: %d\n", max_node->number);
	if ((*stack_a) == max_node)
		ra(stack_a);
	else if ((*stack_a)->next == max_node)
		rra(stack_a);
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
}

void get_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *min_node;
	int target;

	while (stack_size(*stack_a) > 3)
	{
		min_node = find_min(*stack_a);
		target = min_node->number;
		set_index(*stack_a, target);
		above_median(*stack_a);
		while((*stack_a)->number != target)
		{
			if ((*stack_a)->above_median == 1)
				ra(stack_a);
			else
				rra(stack_a);
			printf("index: %d\n", (*stack_a)->index);
			printf("above median: %d\n", (*stack_a)->above_median);
			(*stack_a) = (*stack_a) -> next;
		}
		pb(stack_b, stack_a);
	}
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a) <= 3)
		sort_three(&stack_a);
	else
	{
		get_three(&stack_a, &stack_b);
		sort_three(&stack_a);
		while (stack_b)
			pa(&stack_a, &stack_b);
	}
}
