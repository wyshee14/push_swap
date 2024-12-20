/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:45:07 by wshee             #+#    #+#             */
/*   Updated: 2024/12/20 21:01:18 by wshee            ###   ########.fr       */
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
	init_stack(&stack_a, argv[i]);
}
