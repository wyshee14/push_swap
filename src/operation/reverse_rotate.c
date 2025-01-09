/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:12:36 by wshee             #+#    #+#             */
/*   Updated: 2025/01/08 15:31:30 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (*stack == NULL || ((*stack)->next) == NULL)
		return ;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node -> next;
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
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

// 	rra(&stack_a);
// 	print_stack(stack_a, "Stack A after rra");

// 	rrb(&stack_b);
// 	print_stack(stack_b, "Stack B after rrb");

// 	rrr(&stack_a, &stack_b);
// 	print_stack(stack_a, "Stack A after rrr");
// 	print_stack(stack_b, "Stack B after rrr");
// }
