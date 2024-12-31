/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:26:03 by wshee             #+#    #+#             */
/*   Updated: 2024/12/31 15:28:56 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int stack_size(t_stack *stack)
{
	int count;

	count = 0;
	if(!stack)
		return(0);
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return(count);
}
