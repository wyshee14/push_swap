/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:37:32 by wshee             #+#    #+#             */
/*   Updated: 2025/01/07 19:43:51 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int partition(int *arr, int low, int high)
{
	int pivot_number;
	int i;
	int j;

	pivot_number = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot_number)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

//Find the partition index(pivot)
//first recursively sort the left half
//second recursively sort the right half
void quicksort(int *arr, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}

void init_array(int *arr, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i] = stack->number;
		//printf("%d\n", arr[i]);
		stack = stack->next;
		i++;
	}
}

int set_index_to_stack(int *arr,int low, int high, int key)
{
	int mid;

	mid = 0;
	while(low <= high)
	{
		mid = low + ((high - low) / 2);
		if (arr[mid] == key)
		{
			return(mid);
		}
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return(-1);
}

void pre_sort(t_stack **stack_a)
{
	int *arr;
	int index;
	int size;

	size = stack_size(*stack_a);
	printf("size: %d\n", size);
	arr = (int *)malloc(sizeof(int) * size);
	if(!arr)
		return ;
	init_array(arr, *stack_a);
	int i = 0;
	while (i < size)
	{
		// printf("Array: ");
		// printf("%d ", arr[i]);
		i++;
	}
	quicksort(arr, 0, size - 1);
	while (stack_a != NULL && *stack_a != NULL)
	{
		index = set_index_to_stack(arr, 0, size - 1, (*stack_a)->number);
		if (index != -1)
		{
			(*stack_a)->index = index;
		}
		// printf("number: %d, index: %d\n", (*stack_a)->number, (*stack_a)->index);
		stack_a = &(*stack_a)->next;
	}
	free(arr);
}
