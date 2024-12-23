/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:12:36 by wshee             #+#    #+#             */
/*   Updated: 2024/12/23 22:08:03 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack *last_node;

	if (*stack == NULL || ((*stack) -> next) == NULL)
		return ;
	last_node = *stack;
	while (last_node -> next != NULL)
		last_node = last_node -> next;
	last_node -> prev -> next = NULL;
	last_node -> next = *stack;
	last_node -> prev = NULL;
	(*stack) -> prev = last_node;
	(*stack) = last_node;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
