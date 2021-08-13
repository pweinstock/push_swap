/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:02:01 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/11 16:33:01 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_3(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (third > first && first > second)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > third && third > second)
		ra(stack);
	else if (second > third && third > first)
	{
		sa(stack);
		ra(stack);
	}
	else if (second > first && first > third)
		rra(stack);
}

void	_0_10(t_list **a, t_list **b)
{
	int	i;

	i = 0;
	while (ft_stacksize(a) > 2 && ft_sort_check(a) == 0)
	{
		ft_index_to_top(a, ft_minindex(a));
		pb(a, b);
		i++;
	}
	if (ft_sort_check(a) == 0 && ft_stacksize(a) == 1)
		sa(a);
	else if (ft_sort_check(a) == 0)
		_3(a);
	while (i)
	{
		pa(a, b);
		i--;
	}
}

void	_11_100(t_list **a, t_list **b)
{
	ft_push_4_chunks(a, b);
	if (ft_stacksize(a) > 10)
		ft_push_4_chunks(a, b);
	_0_10(a, b);
	ft_push_chunks_back(a, b);
}

void	_101_500(t_list **a, t_list **b)
{
	ft_push_8_chunks_1(a, b);
	if (ft_stacksize(a) > 10)
		ft_push_4_chunks(a, b);
	_0_10(a, b);
	ft_push_chunks_back(a, b);
}

void	ft_sort(t_list **a, t_list **b)
{
	if (ft_stacksize(a) + 1 <= 10)
		_0_10(a, b);
	else if (ft_stacksize(a) + 1 <= 101)
		_11_100(a, b);
	else
		_101_500(a, b);
}
