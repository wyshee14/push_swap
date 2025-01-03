/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:22:51 by wshee             #+#    #+#             */
/*   Updated: 2025/01/03 13:29:54 by wshee            ###   ########.fr       */
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

// void above_median(t_stack *stack)
// {
// 	int median;

// 	median = stack_size(stack) / 2;
// 	while (stack)
// 	{
// 		if (stack->index < median)
// 			stack->above_median = 1;
// 		else
// 			stack->above_median = 0;
// 		stack = stack->next;
// 		printf("above median: %d\n", stack->above_median);
// 	}
// }

//set the target node in stack b
// void set_target_nodes(t_stack *stack_a, t_stack *b)
// {
// 	t_stack *current_b;
// 	t_sta
// }

// void set_stack(t_stack *stack_a)
// {
// 	set_index(stack_a);
// 	set_index(stack_b);
// 	set_target_nodes(stack_a);
// }
