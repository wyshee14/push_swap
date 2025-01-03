/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:37:32 by wshee             #+#    #+#             */
/*   Updated: 2025/01/03 22:53:18 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void swap(t_stack *i, t_stack *j)
{
	int temp;

	temp = i->number;
	i->number = j->number;
	j->number = temp;
}

t_stack *partition(t_stack *low, t_stack *high)
{
	int pivot;
	t_stack *i;
	t_stack *j;

	pivot = high->number;
	i = low->prev;
	j = low;
	while (j != high)
	{
		if (j->number <= pivot)
		{
			if (i == NULL)
				i = low;
			else
				i = i->next;
			swap(i, j);
		}
		j = j-> next;
	}
	if (i == NULL)
		i = low;
	else
		i = i->next;
	swap(i, high);
	return (i);
}

//Find the partiion node(pivot)
//first recursively sort the left half
//second recursively sort the right half
void quicksort(t_stack **stack_a, t_stack *low, t_stack *high)
{
	t_stack *pivot;

	if (low != NULL && high != NULL && low != high && low != high->next)
	{
		pivot = partition(low, high);
		quicksort(*stack_a, low, pivot->prev);
		quicksort(*stack_a, pivot->next, high);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *low;
	t_stack *high;

	low = *stack_a;
	high = get_last_node(*stack_a);
	quicksort(stack_a, low, high);


}
