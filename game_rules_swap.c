/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:37:58 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/10 17:11:42 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *stack;
	*stack = (*stack)->next;
	ptr2 = (*stack)->next;
	(*stack)->next = ptr1;
	(*stack)->next->next = ptr2;
}

void	sa(t_list **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
