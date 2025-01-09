/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:45:07 by wshee             #+#    #+#             */
/*   Updated: 2025/01/09 17:29:41 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**get_input(int ac, char **av)
{
	char **split;
	char *res;
	char *join;
	char *temp;
	int i;

	if(ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
	{
		i = 1;
		res = ft_strdup("");
		while (av[i])
		{
			temp = ft_strjoin(av[i], " ");
			join = res;
			res = ft_strjoin(join, temp);
			free(temp);
			free(join);
			i++;
		}
		split = ft_split(res, ' ');
		free(res);
		return (split);
	}
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int count_arg;
	char	**input;

	stack_a = NULL;
	stack_b = NULL;
	count_arg = 0;
	input = get_input(argc, argv);
	while (input[count_arg])
		count_arg++;
	if ((count_arg == 1 && is_numeric(input[0])) || count_arg == 0)
	{
		free_2d(input);
		exit(1);
	}
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
	free_stack(&stack_a);
	free_stack(&stack_b);
	return(0);
}
