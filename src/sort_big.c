/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:58:59 by wshee             #+#    #+#             */
/*   Updated: 2025/01/08 17:42:53 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//find the largest number
//find the second largest number in stack b
//rotate to the top of stack for ready to push
int	max_two_top(t_stack **stack_a, t_stack **stack_b, int *arr_b, int size_b)
{
	int	max;
	int	index;
	int	swap;

	max = size_b - 1;
	index = set_index(*stack_b, max, 'b');
	swap = 0;
	while ((*stack_b)->index != max)
	{
		if ((*stack_b)->index == (arr_b[size_b - 2]) && swap == 0)
		{
			pa(stack_a, stack_b);
			swap = 1;
		}
		else
		{
			if (index < size_b / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
	return (swap);
}

static void	init_array_b(int *arr, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i] = stack->index;
		stack = stack->next;
		i++;
	}
}

static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	*arr_b;
	int	size_b;

	size_b = stack_size(*stack_b);
	arr_b = (int *)malloc(sizeof(int) * size_b);
	init_array_b(arr_b, *stack_b);
	quicksort(arr_b, 0, size_b - 1);
	while (size_b > 0)
	{
		if (max_two_top(stack_a, stack_b, arr_b, size_b) == 1)
		{
			pa(stack_a, stack_b);
			size_b -= 2;
			if (size_b > 1 && (*stack_b)->index < (*stack_b)->next->index)
				ss(stack_a, stack_b);
			else
				sa(stack_a);
		}
		else
		{
			pa(stack_a, stack_b);
			size_b--;
		}
	}
	free(arr_b);
}

static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b, int n)
{
	int	partition;
	int	pb_count;
	int	size_a;
	int	size_b;

	pb_count = 0;
	size_a = stack_size(*stack_a);
	partition = (size_a / 20) + 30;
	while (size_a > 0)
	{
		if ((*stack_a)->index < (partition * n))
		{
			pb(stack_b, stack_a);
			size_b = stack_size(*stack_b);
			if (size_b > 1
				&& (*stack_b)->index <= partition * n - (partition / 2))
				rb(stack_b);
			pb_count++;
			size_a--;
		}
		else
			ra(stack_a);
		if (pb_count == partition * n)
			n++;
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	pre_sort(stack_a);
	move_a_to_b(stack_a, stack_b, 1);
	move_b_to_a(stack_a, stack_b);
}
