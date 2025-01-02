/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:45:07 by wshee             #+#    #+#             */
/*   Updated: 2025/01/02 22:15:37 by wshee            ###   ########.fr       */
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
	while (input[i])
	{
		printf("%d: %s\n", i, input[i]);
		i++;
	}
	init_stack(&stack_a, input);
	if (!stack_sorted(stack_a))
	{
		//int size = stack_size(stack_a);
		//printf("size: %d\n", size);
		if (stack_size(stack_a) == 2)
			sa(&stack_a);
		else if (stack_size(stack_a) <= 15)
			sort_small(stack_a, stack_b);
		// else
		// {
		// 	set_stack(stack_a);
		// 	do_sort(stack_a, stack_b);
		// }
	}
	while(stack_a != NULL)
	{
		printf("%d\n", stack_a -> number);
		stack_a = stack_a -> next;
	}
	while(stack_b != NULL)
	{
		printf("%d\n", stack_b -> number);
		stack_b = stack_b -> next;
	}
}
