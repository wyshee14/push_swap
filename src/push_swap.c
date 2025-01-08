/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:45:07 by wshee             #+#    #+#             */
/*   Updated: 2025/01/08 22:05:36 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

char **get_input(int ac, char **av)
{
	if(ac < 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
	char **split;
	if (ac == 2 && av[1][0] != '\0')
	{
		split = ft_split(av[1], ' ');
		return(split);
	}
	return(av + 1);
}

void free_2d(char **av)
{
	int i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;
	char **input;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	input = get_input(argc, argv);
	// while (input[i])
	// {
	// 	printf("%d: %s\n", i, input[i]);
	// 	i++;
	// }
	init_stack(&stack_a, input);
	if (!stack_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a);
		else if (stack_size(stack_a) <= 15)
			sort_small(&stack_a, &stack_b);
		else
			sort_big(&stack_a, &stack_b);
	}
	// int size_a = stack_size(stack_a);
	// printf("size a: %d\n", size_a);
	// int size_b = stack_size(stack_b);
	// printf("size b: %d\n", size_b);
	// while(stack_a != NULL)
	// {
	// 	printf("a: %d\n", stack_a->number);
	// 	stack_a = stack_a->next;
	// }
	// while(stack_b != NULL)
	// {
	// 	printf("b: %d\n", stack_b->number);
	// 	stack_b = stack_b->next;
	// }
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_2d(input);
	return(0);
}

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
