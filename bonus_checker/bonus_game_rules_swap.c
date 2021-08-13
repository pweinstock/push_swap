/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game_rules_swap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:37:58 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/13 14:37:57 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

void	bonus_swap(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *stack;
	*stack = (*stack)->next;
	ptr2 = (*stack)->next;
	(*stack)->next = ptr1;
	(*stack)->next->next = ptr2;
}

int	bonus_sa(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	swap(stack);
	return (1);
}

int	bonus_sb(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	swap(stack);
	return (1);
}

int	bonus_ss(t_list **a, t_list **b)
{
	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return (0);
	swap(a);
	swap(b);
	return (1);
}
