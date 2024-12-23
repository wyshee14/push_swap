/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:06:40 by wshee             #+#    #+#             */
/*   Updated: 2024/12/20 21:00:21 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack) -> next == NULL)
		return ;
	first = *stack;
	second = first -> next;
	if ((second -> next) != NULL)
		second -> next -> prev = first;
	first -> next = second -> next;
	first -> prev = second;
	second -> next = first;
	second -> prev = NULL;
	*stack = second;
}

void sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
