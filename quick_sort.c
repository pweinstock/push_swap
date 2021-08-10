/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:21:40 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/10 17:15:06 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function to swap elements
static void	sswap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

// function to find the partition position
static int	partition(int *array, int low, int high)
{
	// select the rightmost t_list as pivot
	int	pivot;

	// pointer for greater t_list
	int	i;	
	// traverse each t_list of the array
	// compare them with the pivot
	pivot = array[high];
	i = (low - 1);
	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
		// if t_list smaller than pivot is found
		// swap it with the greater t_list pointed by i
			i++;
		// swap t_list at i with t_list at j
		sswap(&array[i], &array[j]);
		}
	}
	// swap the pivot t_list with the greater t_list at i
	sswap(&array[i + 1], &array[high]);

	// return the partition point
	return (i + 1);
}

void	quickSort(int *array, int low, int high)
{
	if (low < high)
	{

	// find the pivot t_list such that
	// elements smaller than pivot are on left of pivot
	// elements greater than pivot are on right of pivot
		int	pi;

		pi = partition(array, low, high);
	// recursive call on the left of pivot
		quickSort(array, low, pi - 1);

	// recursive call on the right of pivot
		quickSort(array, pi + 1, high);
	}
}

void	ft_stack_array_4(t_list **stack, t_chunks *chunk)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * (ft_stacksize(stack) + 1));
	while(*stack)
	{
		array[i] = (*stack)->content;
		stack = &(*stack)->next;
		i++;
	}
	quickSort(array, 0, i - 1);
	chunk->index1 = array[(i / 4) - 1];
	chunk->index2 = array[((i / 4) * 2) - 1];
	chunk->index3 = array[((i / 4) * 3) - 1];
}

void	ft_stack_array_8(t_list **stack, t_chunks *chunk)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * (ft_stacksize(stack) + 1));
	while (*stack)
	{
		array[i] = (*stack)->content;
		stack = &(*stack)->next;
		i++;
	}
	quickSort(array, 0, i - 1);
	chunk->index1 = array[(i / 8) - 1];
	chunk->index2 = array[((i / 8) * 2) - 1];
	chunk->index3 = array[((i / 8) * 3) - 1];
	chunk->index4 = array[((i / 8) * 4) - 1];
	chunk->index5 = array[((i / 8) * 5) - 1];
	chunk->index6 = array[((i / 8) * 6) - 1];
	chunk->index7 = array[((i / 8) * 7) - 1];
}
