/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:02:01 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/07 18:06:10 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_3(element **stack)
{
	int	first;
	int	second;
	int	third;
	
	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if(third > first && first > second)
		sa(stack);
	else if(first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if(first > third && third > second)
		ra(stack);
	else if(second > third && third > first)
		{
			sa(stack);
			ra(stack);
		}
	else if(second > first && first > third)
		rra(stack);
}

void	_0_10(element **stack_a, element **stack_b)
{
	int	i;

	i = 0;
	while(ft_stacksize(stack_a) > 2 && ft_sort_check(stack_a) == 0)
	{
		ft_index_to_top(stack_a, ft_minindex(stack_a));
		pb(stack_a, stack_b);
		i++;
	}
	if(ft_sort_check(stack_a) == 0)
		_3(stack_a);
	while(i)
	{
		pa(stack_a, stack_b);
		i--;
	}
}

void	_11_100(element **stack_a, element **stack_b)
{
	ft_push_4_chunks(stack_a, stack_b);
	_0_10(stack_a, stack_b);
	ft_push_chunks_back(stack_a, stack_b);
}

void	_101_500(element **stack_a, element **stack_b)
{
	ft_push_8_chunks_1(stack_a, stack_b);
	_0_10(stack_a, stack_b);
	ft_push_chunks_back(stack_a, stack_b);
}
