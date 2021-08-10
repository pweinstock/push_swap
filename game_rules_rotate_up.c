/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules_rotate_up.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:06:52 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/10 17:22:01 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_list **stack)
{
	t_list	*ptr;

	ptr = *stack;
	*stack = (*stack)->next;
	while ((*stack)->next != NULL)
		stack = &(*stack)->next;
	(*stack)->next = ptr;
	(*stack)->next->next = NULL;
}

void	ra(t_list **stack)
{
	rotate_up(stack);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	rotate_up(stack);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate_up(a);
	rotate_up(b);
	write(1, "rr\n", 3);
}
