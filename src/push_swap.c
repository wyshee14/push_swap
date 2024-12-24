/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:45:07 by wshee             #+#    #+#             */
/*   Updated: 2024/12/24 21:57:30 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

char **get_input(int ac, char **av)
{
	char **split;
	if (ac == 2 && av[1][0] != '\0')
	{
		split = ft_split(av[1], ' ');
		return(split);
	}
	return(av);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;
	char **input;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	else
		input = get_input(argc, argv);
	while (input[i])
	{
		printf("%d: %s\n", i, input[i]);
		i++;
	}
	init_stack(&stack_a, input + 1);
	while(stack_a)
	{
		printf("%d\n", stack_a -> number);
		stack_a = stack_a -> next;
	}
	// ra(stack_a);
	// while (i < num_word)
	// {
		// i++;
	// }
}
