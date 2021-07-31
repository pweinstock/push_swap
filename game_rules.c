/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:37:58 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/31 20:57:25 by pweinsto         ###   ########.fr       */
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

void	pa(element **stack_a, element **stack_b)
{
	push(top(*stack_b), stack_a);
	pop(stack_b);
	write(1, "pa\n", 3);
}

void	pb(element **stack_a, element **stack_b)
{
	push(top(*stack_a), stack_b);
	pop(stack_a);
	write(1, "pa\n", 3);
}
#include <stdio.h>
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
