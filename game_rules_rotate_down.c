/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules_rotate_down.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:08:07 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/06 15:12:14 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(element **stack)
{
	element	*ptr1;
	element *ptr2;
	
	ptr1 = *stack;
	while((*stack)->next->next != NULL)
	{
		*stack = (*stack)->next;
	}
	ptr2 = *stack;
	(*stack)->next->next = ptr1;
	*stack = (*stack)->next;
	ptr2->next = NULL;
}

void	rra(element **stack)
{
	rotate_down(stack);
	write(1, "rra\n", 4);
}

void	rrb(element **stack)
{
	rotate_down(stack);
	write(1, "rrb\n", 4);
}

void	rrr(element **stack_a, element **stack_b)
{
	rotate_down(stack_a);
	rotate_down(stack_b);
	write(1, "rrr\n", 4);
}
