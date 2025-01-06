/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:58:59 by wshee             #+#    #+#             */
/*   Updated: 2025/01/06 21:34:14 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//find the largest number
//rotate to the top of stack for ready to push
int	quick_rotate(t_stack *stack_a, t_stack *stack_b, int *arr_b)
{
	int target;
	int index;

	if(!stack_sorted)
		return (0);
	target = stack_size(stack_b) - 1;
	index = set_index(stack_b, target);
	stack_a->index = index;
	while (stack_b->index != target)
}

void	sort_back(t_stack *stack_a, t_stack *stack_b)
{
	int	*arr_b;
	int size_b;

	size_b = stack_size(*stack_b);
	arr_b = (int *)malloc(sizeof(int) * size_b);
	init_array(arr_b, stack_b);
	quicksort(stack_b, 0, size_b - 1);
	while (size_b > 0)
	{
		if (quick_rotate)
	}
}
