/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:06:44 by wshee             #+#    #+#             */
/*   Updated: 2025/01/14 21:42:51 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+') && (str[1] < '0' || str[1] > '9'))
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	handle_duplicate(t_stack *stack, long nbr)
{
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		if (stack-> number == nbr)
			return (1);
		stack = stack -> next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current -> next;
		free(temp);
	}
	*stack = NULL;
}

void	print_error(t_stack **stack_a, char **input)
{
	free_2d(input);
	free_stack(stack_a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
