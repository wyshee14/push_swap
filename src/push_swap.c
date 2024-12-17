/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:45:07 by wshee             #+#    #+#             */
/*   Updated: 2024/12/16 14:29:22 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack(t_list *stack, int argc, char **argv)
{
	t_list	*new;
	int	i;

	i = 1;
	while (argv[i])
	{
		stack = ft_lstnew(argv);
		i++;
	}
}

#include <stdio.h>
int main(int argc, char **argv)
{
	t_list **stack_a;
	t_list **stack_b;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	else if (argc == 2)
		agrv = ft_split(argv[1], ' ');
	else
	{
		char *argv =
	}
}
