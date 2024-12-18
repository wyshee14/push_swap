/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:18:14 by wshee             #+#    #+#             */
/*   Updated: 2024/12/17 17:10:53 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// rotate the first node to become the last node
// assign the first and last node
// check if the stack is empty and more than 1 node
// set the firstnode as the last node
// detach the first node and update the pointer to the second node
// update the pointer to rotate in the stack
void rotate(t_list **stack)
{
	t_list *first_node;
	t_list *last_node;

	if (*stack == NULL || ((*stack) -> next) == NULL)
		return ;
	first_node = *stack;
	last_node = ft_lstlast(*stack);
	last_node -> next = first_node;
	first_node -> prev = last_node;
	*stack = (*stack) -> next;
	(*stack) -> prev == NULL;
	last_node -> next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
