/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:26:03 by wshee             #+#    #+#             */
/*   Updated: 2025/01/08 16:39:21 by wshee            ###   ########.fr       */
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

//set index and position of median in the stack
int set_index(t_stack *stack, int target, char stack_type)
{
	int i;

	i = 0;
	while (stack_type == 'a' && stack->number != target && stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	while (stack_type == 'b' && stack->index != target && stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void ft_swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
