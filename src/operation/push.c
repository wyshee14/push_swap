/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:41:22 by wshee             #+#    #+#             */
/*   Updated: 2025/01/03 15:59:23 by wshee            ###   ########.fr       */
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
static void	push(t_stack **dest, t_stack **src)
{
	t_stack *push_node;

	if (*src == NULL)
		return ;
	push_node = *src;
	*src = (*src) -> next;
	if (*src != NULL)
		(*src) -> prev = NULL;
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

//Main function
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

// void new_stack_push(t_stack **stack, int value)
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
// 	ft_printf("%s: ", name);
// 	while (stack)
// 	{
// 		ft_printf("%d ", stack -> number);
// 		stack = stack -> next;
// 	}
// 	ft_printf("\n");
// }

// int main()
// {
// 	t_stack *stack_a = NULL;
// 	t_stack *stack_b = NULL;

// 	new_stack_push(&stack_a, 3);
// 	new_stack_push(&stack_a, 2);
// 	new_stack_push(&stack_a, 1);

// 	new_stack_push(&stack_b, 6);
// 	new_stack_push(&stack_b, 5);
// 	new_stack_push(&stack_b, 4);

// 	print_stack(stack_a, "Stack A");
// 	print_stack(stack_b, "Stack B");

// 	pa(&stack_a, &stack_b);
// 	print_stack(stack_a, "Stack A after pa");
// 	print_stack(stack_b, "Stack A after pa");

// 	pb(&stack_b, &stack_a);
// 	print_stack(stack_b, "Stack B after pb");
// 	print_stack(stack_a, "Stack A after pa");
// }
