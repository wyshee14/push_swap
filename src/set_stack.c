/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:22:51 by wshee             #+#    #+#             */
/*   Updated: 2025/01/06 17:10:10 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//set index and position of median in the stack
int set_index(t_stack *stack, int min)
{
	int i;

	i = 0;
	while (stack->number != min && stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void above_median(t_stack *stack)
{
	int median;

	median = stack_size(stack) / 2;
	while (stack)
	{
		if (stack->index < median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		//printf("above median: %d\n", stack->above_median);
	}
}

//set the target node of each node in A in stack b
void set_target_a(t_stack *stack_a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	target_small;

	while(stack_a)
	{
		target_small = LONG_MIN;

	}
}

void init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	above_median(stack_a);
	set_target_a(stack_a, stack_b);
	cost_analysis_a
	set_cheapest
}
