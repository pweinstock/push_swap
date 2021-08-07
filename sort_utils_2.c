/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:59:49 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/07 18:05:30 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_check(element **stack)
{
	while((*stack)->next != NULL)
	{
		if((*stack)->content >= (*stack)->next->content)
			return (0);
		stack = &(*stack)->next;
	}
	return(1);
}

void	ft_push_4_chunks(element **stack_a, element **stack_b)
{
	chunks	chunk;
	int	stack_a_size;
	int	i;

	stack_a_size = ft_stacksize(stack_a) + 1;
	ft_stack_array_4(stack_a, &chunk);
	i = 0;
	while(i < (stack_a_size / 4))
	{
		ft_index_to_top(stack_a, ft_get_index(stack_a, chunk.index1));
		pb(stack_a, stack_b);
		i++;
	}
	while(i < (stack_a_size / 4) * 2)
	{
		ft_index_to_top(stack_a, ft_get_index(stack_a, chunk.index2));
		pb(stack_a, stack_b);
		i++;
	}
	while(i < (stack_a_size / 4) * 3)
	{
		ft_index_to_top(stack_a, ft_get_index(stack_a, chunk.index3));
		pb(stack_a, stack_b);
		i++;
	}
}

void	ft_push_8_chunks_1(element **stack_a, element **stack_b)
{
	chunks	chunk;
	chunks_para	para;

	para.stack_a_size = ft_stacksize(stack_a) + 1;
	ft_stack_array_8(stack_a, &chunk);
	para.i = 0;
	while(para.i < (para.stack_a_size / 8))
	{
		ft_index_to_top(stack_a, ft_get_index(stack_a, chunk.index1));
		pb(stack_a, stack_b);
		para.i++;
	}
	while(para.i < (para.stack_a_size / 8) * 2)
	{
		ft_index_to_top(stack_a, ft_get_index(stack_a, chunk.index2));
		pb(stack_a, stack_b);
		para.i++;
	}
	ft_push_8_chunks_2(stack_a, stack_b, chunk, para);
}

void	ft_push_8_chunks_2(element **stack_a, element **stack_b, chunks chunk, chunks_para para)
{
	while(para.i < (para.stack_a_size / 8) * 3)
	{
		ft_index_to_top(stack_a, ft_get_index(stack_a, chunk.index3));
		pb(stack_a, stack_b);
		para.i++;
	}
	while(para.i < (para.stack_a_size / 8) * 4)
	{
		ft_index_to_top(stack_a, ft_get_index(stack_a, chunk.index4));
		pb(stack_a, stack_b);
		para.i++;
	}
	ft_push_8_chunks_3(stack_a, stack_b, chunk, para);
}

void	ft_push_8_chunks_3(element **stack_a, element **stack_b, chunks chunk, chunks_para para)
{
	while(para.i < (para.stack_a_size / 8) * 5)
	{
		ft_index_to_top(stack_a, ft_get_index(stack_a, chunk.index5));
		pb(stack_a, stack_b);
		para.i++;
	}
	while(para.i < (para.stack_a_size / 8) * 6)
	{
		ft_index_to_top(stack_a, ft_get_index(stack_a, chunk.index6));
		pb(stack_a, stack_b);
		para.i++;
	}
	while(para.i < (para.stack_a_size / 8) * 7)
	{
		ft_index_to_top(stack_a, ft_get_index(stack_a, chunk.index7));
		pb(stack_a, stack_b);
		para.i++;
	}
}

void	ft_push_chunks_back(element **stack_a, element **stack_b)
{
	int	stack_b_size;

	stack_b_size = ft_stacksize(stack_b) + 1;
	while(stack_b_size)
	{
		ft_index_to_top_b(stack_b, ft_maxindex(stack_b));
		pa(stack_a, stack_b);
		stack_b_size--;
	}
}