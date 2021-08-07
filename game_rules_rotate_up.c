/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules_rotate_up.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:06:52 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/06 15:09:01 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(element **stack)
{
	element	*ptr;
	
	ptr = *stack;
	*stack = (*stack)->next;
	while((*stack)->next != NULL)
	{
		stack = &(*stack)->next;
	}
	(*stack)->next = ptr;
	(*stack)->next->next = NULL;
}

void	ra(element **stack)
{
	rotate_up(stack);
	write(1, "ra\n", 3);
}

void	rb(element **stack)
{
	rotate_up(stack);
	write(1, "rb\n", 3);
}

void	rr(element **stack_a, element **stack_b)
{
	rotate_up(stack_a);
	rotate_up(stack_b);
	write(1, "rr\n", 3);
}
