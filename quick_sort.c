/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:21:40 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/13 11:27:23 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sswap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			sswap(&array[i], &array[j]);
		}
		j++;
	}
	sswap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	quickSort(int *array, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}

void	ft_stack_array_4(t_list **stack, t_chunks *chunk)
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
	chunk->index1 = array[(i / 4) - 1];
	chunk->index2 = array[((i / 4) * 2) - 1];
	chunk->index3 = array[((i / 4) * 3) - 1];
	free(array);
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
	free(array);
}
