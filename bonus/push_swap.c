/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:45:07 by wshee             #+#    #+#             */
/*   Updated: 2025/01/09 18:49:09 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*str_join(char **av)
{
	char	*res;
	char	*join;
	char	*temp;
	int		i;

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
	return (res);
}

static char	**get_input(int ac, char **av)
{
	char	**split;
	char	*res;

	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
	{
		res = str_join(av);
		split = ft_split(res, ' ');
		free(res);
		return (split);
	}
}

void	validate_input(char **input)
{
	int		count_arg;

	count_arg = 0;
	while (input[count_arg])
		count_arg++;
	if ((count_arg == 1 && is_numeric(input[0])) || count_arg == 0)
	{
		free_2d(input);
		exit(1);
	}
}

void	do_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_sorted(*stack_a))
	{
		if (stack_size(*stack_a) == 2)
			sa(stack_a);
		else if (stack_size(*stack_a) <= 15)
			sort_small(stack_a, stack_b);
		else
			sort_big(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;

	stack_a = NULL;
	stack_b = NULL;
	input = get_input(argc, argv);
	validate_input(input);
	init_stack(&stack_a, input);
	do_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
