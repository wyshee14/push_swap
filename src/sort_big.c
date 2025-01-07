/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:58:59 by wshee             #+#    #+#             */
/*   Updated: 2025/01/07 20:06:34 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//find the second largest number in stack b
static int second_max_push(t_stack **stack_b, int *arr_b, int size_b)
{
	if ((*stack_b)->index == arr_b[size_b - 2])
		return(1);
	return(0);
}

//find the largest number
//rotate to the top of stack for ready to push
static int	max_two_on_top(t_stack **stack_a, t_stack **stack_b, int *arr_b, int size_b)
{
	int max;
	int index;

	if(arr_b == NULL)
		return (0);
	max = size_b - 1;
	index = set_index(*stack_b, max);
	(*stack_a)->index = index;
	while ((*stack_b)->index != max)
	{
		if(second_max_push(stack_b, arr_b, size_b) == 0)
		{
			if(index < size_b / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		else
		{
			pa(stack_a, stack_b);
			return(1);
		}
	}
	return (1);
}

static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	*arr_b;
	int size_b;

	size_b = stack_size(*stack_b);
	arr_b = (int *)malloc(sizeof(int) * size_b);
	init_array(arr_b, *stack_b);
	quicksort(arr_b, 0, size_b - 1);
	while (size_b > 0)
	{
		if (max_two_on_top(stack_a, stack_b, arr_b, size_b) == 1)
		{
			pa(stack_a, stack_b);
			size_b = stack_size(*stack_b);
			if(size_b > 1 && (*stack_b)->index < (*stack_b)->next->index)
				ss(stack_a, stack_b);
			else
				sa(stack_a);
		}
		else
			pa(stack_a, stack_b);
	}
	free(arr_b);
}

static void move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int partition_size;
	int n;
	int pb_count;
	int size_a;

	n = 1;
	pb_count = 0;
	size_a = stack_size(*stack_a);
	partition_size = (size_a / 20) + 30;
	while (size_a >= 0)
	{
		if((*stack_a)->index <= (partition_size * n))
		{
			pb(stack_b, stack_a);
			if ((*stack_a)->index <= partition_size * n - (partition_size / 2))
				rb(stack_b);
			pb_count++;
		}
		else
			ra(stack_a);
		if ((pb_count == partition_size * n) && (partition_size * n) < size_a)
			n++;
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	pre_sort(stack_a);
	move_a_to_b(stack_a, stack_b);
	move_b_to_a(stack_a, stack_b);
}
