/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:45:07 by wshee             #+#    #+#             */
/*   Updated: 2024/12/23 19:29:33 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack **stack_a;
	t_stack **stack_b;
	int i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	int num_word = count_word(argv[1], ' ');
	init_stack(stack_a, &argv[i]);
	ra(stack_a);
	while (i < num_word)
	{
		printf("%s ", argv[i]);
		i++;
	}
}
