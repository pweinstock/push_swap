/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules_rotate_down.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:08:07 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/10 17:11:07 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *stack;
	while ((*stack)->next->next != NULL)
		*stack = (*stack)->next;
	ptr2 = *stack;
	(*stack)->next->next = ptr1;
	*stack = (*stack)->next;
	ptr2->next = NULL;
}

void	rra(t_list **stack)
{
	rotate_down(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	rotate_down(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rotate_down(a);
	rotate_down(b);
	write(1, "rrr\n", 4);
}
