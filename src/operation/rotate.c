/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:18:14 by wshee             #+#    #+#             */
/*   Updated: 2025/01/03 16:00:14 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// rotate the first node to become the last node
// assign the first and last node
// check if the stack is empty and more than 1 node
// set the firstnode as the last node
// detach the first node and update the pointer to the second node
// update the pointer to rotate in the stack
static void rotate(t_stack **stack)
{
	t_stack *first_node;
	t_stack *last_node;

	if (*stack == NULL || ((*stack)->next) == NULL)
		return ;
	first_node = *stack;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	*stack = first_node->next;
	(*stack)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

// Main function
// t_stack *new_node(int value)
// {
// 	t_stack *node = malloc(sizeof(t_stack));
// 	if(!node)
// 		return (NULL);
// 	node -> number = value;
// 	node -> next = NULL;
// 	node -> prev = NULL;
// 	return (node);
// }

// void push(t_stack **stack, int value)
// {
// 	t_stack *node = new_node(value);
// 	if(!node)
// 		return ;
// 	if (*stack != NULL)
// 	{
// 		node -> next = *stack;
// 		(*stack) -> prev = node;
// 	}
// 	*stack = node;
// }

// void print_stack(t_stack *stack, const char *name)
// {
// 	printf("%s: ", name);
// 	while (stack)
// 	{
// 		printf("%d ", stack -> number);
// 		stack = stack -> next;
// 	}
// 	printf("\n");
// }

// int main()
// {
// 	t_stack *stack_a = NULL;
// 	t_stack *stack_b = NULL;

// 	push(&stack_a, 3);
// 	push(&stack_a, 2);
// 	push(&stack_a, 1);

// 	push(&stack_b, 6);
// 	push(&stack_b, 5);
// 	push(&stack_b, 4);

// 	print_stack(stack_a, "Stack A");
// 	print_stack(stack_b, "Stack B");

// 	ra(&stack_a);
// 	print_stack(stack_a, "Stack A after ra");

// 	rb(&stack_b);
// 	print_stack(stack_b, "Stack B after rb");

// 	rr(&stack_a, &stack_b);
// 	print_stack(stack_a, "Stack A after rr");
// 	print_stack(stack_b, "Stack B after rr");
// }
