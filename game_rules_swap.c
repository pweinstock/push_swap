/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:37:58 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/06 15:12:31 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(element **stack)
{
	element	*ptr1;
	element *ptr2;
	
	ptr1 = *stack;
	*stack = (*stack)->next;
	ptr2 = (*stack)->next;
	(*stack)->next = ptr1;
	(*stack)->next->next = ptr2;	
}

void	sa(element **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(element **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(element **stack_a, element **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
