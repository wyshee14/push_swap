#include "../include/push_swap.h"

int stack_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		if (stack->number > stack->next->number)
			return(1);
		stack = stack->next;
	}
	return(0);
}

t_stack *find_max(t_stack *stack)
{
	t_stack *max_node;
	long	max;

	if(!stack)
		return (NULL);
	max = stack -> number;
	while(stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack-> next;
	}
	return (max_node);
}

void	sort_three(t_stack **stack_a)
{
	t_stack *max_node;

	max_node = find_max(*stack_a);
	if ((*stack_a) == max_node)
		ra(stack_a);
	else if ((*stack_a)->next == max_node)
		rra(stack_a);
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
}
