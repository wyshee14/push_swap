/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:06:40 by wshee             #+#    #+#             */
/*   Updated: 2024/12/29 18:13:46 by wshee            ###   ########.fr       */
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

// 	sa(&stack_a);
// 	print_stack(stack_a, "Stack A after sa");

// 	sb(&stack_b);
// 	print_stack(stack_b, "Stack B after sb");

// 	ss(&stack_a, &stack_b);
// 	print_stack(stack_a, "Stack A after ss");
// 	print_stack(stack_b, "Stack B after ss");
// }
