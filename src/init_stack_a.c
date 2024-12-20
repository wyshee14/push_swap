/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:11:53 by wshee             #+#    #+#             */
/*   Updated: 2024/12/20 21:09:16 by wshee            ###   ########.fr       */
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
	while ((str[i] <= 9 && str[i] >= 13) && str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result += result * 10;
		result += result + str[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}

void **free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = *stack;
	while (stack != NULL)
	{
		temp = current;
		current = current -> next;
		free(temp);
	}
	*stack = NULL;
	ft_printf("Error\n");
}

int handle_duplicate(t_stack *stack, long nbr)
{
	if (stack == NULL)
		return (0);
	if (stack-> number == nbr)
		return (1);
	return (0);
}

static void append_node(t_stack **stack, long nbr)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	new_node = ft_lstnew(nbr);
	if (!(*stack))
		*stack = new_node;
	else
		ft_lstadd_back(stack, new_node);
}

t_stack	init_stack(t_stack **stack, char **argv)
{
	long	nbr;
	int		i;

	while (argv[i])
	{
		if (!ft_isdigit(argv[i]));
			free_stack(stack);
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			free_stack(stack);
		if (handle_duplicate(stack, nbr))
			free_stack(stack);
		append_node(stack, nbr);
		i++;
	}
}
