/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:18:08 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/06 19:30:25 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(element **stack)
{
	int	i;

	i = 0;
	while((*stack)->next != NULL)
	{
		stack = &(*stack)->next;
		i++;
	}
	return (i);
}

int	ft_minindex(element **stack)
{
	int	min;
	int	index;
	int	minindex;

	min = 2147483647;
	index = 0;
	minindex = 0;
	while((*stack)->next != NULL)
	{
		if((*stack)->content < min)
		{
			min = (*stack)->content;
			minindex = index;
		}
		stack = &(*stack)->next;
		index++;
	}
	if((*stack)->content < min)
		{
			min = (*stack)->content;
			minindex = index;
		}
	return (minindex);
}

int	ft_maxindex(element **stack)
{
	int	max;
	int	index;
	int	maxindex;

	max = -2147483648;
	index = 0;
	maxindex = 0;
	while((*stack)->next != NULL)
	{
		if((*stack)->content > max)
		{
			max = (*stack)->content;
			maxindex = index;
		}
		stack = &(*stack)->next;
		index++;
	}
	if((*stack)->content > max)
		{
			max = (*stack)->content;
			maxindex = index;
		}
	return (maxindex);
}

void	ft_index_to_top(element **stack, int index)
{
	int	stacksize;
	int i;

	stacksize = ft_stacksize(stack);
	i = 0;
	if(index <= stacksize / 2)
	{
		while(i < index)
		{
			ra(stack);
			i++;
		}
	}
	else
	{
		while(i <= stacksize - index)
		{
			rra(stack);
			i++;
		}
	}
}

void	ft_index_to_top_b(element **stack, int index)
{
	int	stacksize;
	int i;

	stacksize = ft_stacksize(stack);
	i = 0;
	if(index <= stacksize / 2)
	{
		while(i < index)
		{
			rb(stack);
			i++;
		}
	}
	else
	{
		while(i <= stacksize - index)
		{
			rrb(stack);
			i++;
		}
	}
}

int	ft_get_index(element **stack_a, int index)
{
	int	i;

	i = 0;
	while(*stack_a)
	{
		if((*stack_a)->content <= index)
			return (i);
		stack_a = &(*stack_a)->next;
		i++;
	}
	return (0);
}
