/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:49:28 by wshee             #+#    #+#             */
/*   Updated: 2025/01/14 15:09:33 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	free_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	execute_instructions(t_stack **a, t_stack **b, char *instructions)
{
	if (ft_strncmp(instructions, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(instructions, "pb\n", 3) == 0)
		pb(b, a, 0);
	else if (ft_strncmp(instructions, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(instructions, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(instructions, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else if (ft_strncmp(instructions, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(instructions, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(instructions, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(instructions, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(instructions, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(instructions, "ss\n", 3) == 0)
		ss(a, b, 0);
	else
		free_error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;
	char	*instructions;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	input = get_input(argc, argv);
	init_stack(&stack_a, input);
	len = stack_size(stack_a);
	instructions = get_next_line(STDIN_FILENO);
	while (instructions)
	{
		execute_instructions(&stack_a, &stack_b, instructions);
		free(instructions);
		instructions = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(stack_a) && stack_size(stack_a) == len)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
