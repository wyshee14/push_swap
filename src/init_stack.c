/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:11:53 by wshee             #+#    #+#             */
/*   Updated: 2025/01/02 22:04:34 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long ft_atol(const char *str)
{
	int i;
	int sign;
	long result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}

static void append_node(t_stack **stack, long nbr)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node -> number = nbr;
	new_node -> next = NULL;
	if ((*stack) == NULL)
	{
		*stack = new_node;
		new_node -> prev = NULL;
	}
	else
	{
		last_node = *stack;
		while (last_node->next != NULL)
			last_node = last_node -> next;
		last_node -> next = new_node;
		new_node -> prev = last_node;
	}
}

void	init_stack(t_stack **stack_a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!is_numeric(argv[i]))
			print_error(stack_a);
		nbr = ft_atol(argv[i]);
		//printf("%li\n", nbr);
		if (nbr < INT_MIN || nbr > INT_MAX)
			print_error(stack_a);
		if (handle_duplicate((*stack_a), nbr))
			print_error(stack_a);
		append_node(stack_a, nbr);
		i++;
	}
}
