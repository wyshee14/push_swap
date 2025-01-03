/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:26:03 by wshee             #+#    #+#             */
/*   Updated: 2025/01/03 18:00:34 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int stack_size(t_stack *stack)
{
	int count;

	count = 0;
	if(!stack)
		return(0);
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return(count);
}

int stack_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		if (stack->number > stack->next->number)
			return(0);
		stack = stack->next;
	}
	return(1);
}

t_stack *get_last_node(t_stack *last)
{
	if (!last)
		return (NULL);
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}
