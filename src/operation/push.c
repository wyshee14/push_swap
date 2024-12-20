/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:41:22 by wshee             #+#    #+#             */
/*   Updated: 2024/12/20 20:59:33 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Declare a pointer for the node to be pushed
// Check if the stack src exists
// top node to pushed is assigned as src
// move pointer src to the second node, which will become the next node to push
// check if the seconde exist, set the second as current for src
// Detach the push_node from src
// check dest is empty, assign first node in the stack, ensure is the first and last node
// if dest is not empty, assign the push_node to the top, pointer dest move to push_node
void push(t_stack **dest, t_stack **src)
{
	t_stack *push_node;

	if (*src == NULL)
		return ;
	push_node = *src;
	*src = (*src) -> next;
	if (*src != NULL)
		(*src) -> prev == NULL;
	push_node -> prev = NULL;
	if (*dest == NULL)
	{
		*dest = push_node;
		push_node -> next = NULL;
	}
	else
	{
		push_node -> next = *dest;
		(*dest) -> prev = push_node;
		*dest = push_node;
	}
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	push (stack_a, stack_b);
	ft_printf("pa\n");
}

void pb(t_stack **stack_b, t_stack **stack_a)
{
	push (stack_b, stack_a);
	ft_printf("pb\n");
}
