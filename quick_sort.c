/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:21:40 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/07 18:05:34 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function to swap elements
static void	sswap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// function to find the partition position
static int	partition(int *array, int low, int high)
{
	// select the rightmost element as pivot
	int pivot = array[high];

	// pointer for greater element
	int i = (low - 1);	
	// traverse each element of the array
	// compare them with the pivot
	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
		// if element smaller than pivot is found
		// swap it with the greater element pointed by i
		i++;

		// swap element at i with element at j
		sswap(&array[i], &array[j]);
		}
	}
	// swap the pivot element with the greater element at i
	sswap(&array[i + 1], &array[high]);

	// return the partition point
	return (i + 1);
}

void quickSort(int *array, int low, int high)
{
	if (low < high)
	{

	// find the pivot element such that
	// elements smaller than pivot are on left of pivot
	// elements greater than pivot are on right of pivot
	int pi = partition(array, low, high);

	// recursive call on the left of pivot
	quickSort(array, low, pi - 1);

	// recursive call on the right of pivot
	quickSort(array, pi + 1, high);
	}
}

void	ft_stack_array_4(element **stack, chunks *chunk)
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

void	ft_stack_array_8(element **stack, chunks *chunk)
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
	chunk->index1 = array[(i / 8) - 1];
	chunk->index2 = array[((i / 8) * 2) - 1];
	chunk->index3 = array[((i / 8) * 3) - 1];
	chunk->index4 = array[((i / 8) * 4) - 1];
	chunk->index5 = array[((i / 8) * 5) - 1];
	chunk->index6 = array[((i / 8) * 6) - 1];
	chunk->index7 = array[((i / 8) * 7) - 1];
}
