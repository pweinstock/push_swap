/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:59:49 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/10 17:14:07 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_check(t_list **stack)
{
	while ((*stack)->next != NULL)
	{
		if ((*stack)->content >= (*stack)->next->content)
			return (0);
		stack = &(*stack)->next;
	}
	return (1);
}

void	ft_push_4_chunks(t_list **a, t_list **b)
{
	t_chunks	chunk;
	int		stack_a_size;
	int		i;

	stack_a_size = ft_stacksize(a) + 1;
	ft_stack_array_4(a, &chunk);
	i = 0;
	while (i < (stack_a_size / 4))
	{
		ft_index_to_top(a, ft_get_index(a, chunk.index1));
		pb(a, b);
		i++;
	}
	while (i < (stack_a_size / 4) * 2)
	{
		ft_index_to_top(a, ft_get_index(a, chunk.index2));
		pb(a, b);
		i++;
	}
	while (i < (stack_a_size / 4) * 3)
	{
		ft_index_to_top(a, ft_get_index(a, chunk.index3));
		pb(a, b);
		i++;
	}
}

void	ft_push_8_chunks_1(t_list **a, t_list **b)
{
	t_chunks		chunk;
	t_cp	para;

	para.stack_a_size = ft_stacksize(a) + 1;
	ft_stack_array_8(a, &chunk);
	para.i = 0;
	while (para.i < (para.stack_a_size / 8))
	{
		ft_index_to_top(a, ft_get_index(a, chunk.index1));
		pb(a, b);
		para.i++;
	}
	while (para.i < (para.stack_a_size / 8) * 2)
	{
		ft_index_to_top(a, ft_get_index(a, chunk.index2));
		pb(a, b);
		para.i++;
	}
	ft_push_8_chunks_2(a, b, chunk, para);
}

void	ft_push_8_chunks_2(t_list **a, t_list **b, t_chunks chunk, t_cp para)
{
	while (para.i < (para.stack_a_size / 8) * 3)
	{
		ft_index_to_top(a, ft_get_index(a, chunk.index3));
		pb(a, b);
		para.i++;
	}
	while (para.i < (para.stack_a_size / 8) * 4)
	{
		ft_index_to_top(a, ft_get_index(a, chunk.index4));
		pb(a, b);
		para.i++;
	}
	ft_push_8_chunks_3(a, b, chunk, para);
}

void	ft_push_8_chunks_3(t_list **a, t_list **b, t_chunks chunk, t_cp para)
{
	while (para.i < (para.stack_a_size / 8) * 5)
	{
		ft_index_to_top(a, ft_get_index(a, chunk.index5));
		pb(a, b);
		para.i++;
	}
	while (para.i < (para.stack_a_size / 8) * 6)
	{
		ft_index_to_top(a, ft_get_index(a, chunk.index6));
		pb(a, b);
		para.i++;
	}
	while (para.i < (para.stack_a_size / 8) * 7)
	{
		ft_index_to_top(a, ft_get_index(a, chunk.index7));
		pb(a, b);
		para.i++;
	}
}

void	ft_push_chunks_back(t_list **a, t_list **b)
{
	int	stack_b_size;

	stack_b_size = ft_stacksize(b) + 1;
	while (stack_b_size)
	{
		ft_index_to_top_b(b, ft_maxindex(b));
		pa(a, b);
		stack_b_size--;
	}
}
