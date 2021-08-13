/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game_rules_rotate_down.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:08:07 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/13 14:32:12 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

void	bonus_rotate_down(t_list **stack)
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

int	bonus_rra(t_list **stack)
{
	if (*stack == NULL)
		return (0);
	rotate_down(stack);
	return (1);
}

int	bonus_rrb(t_list **stack)
{
	if (*stack == NULL)
		return (0);
	rotate_down(stack);
	return (1);
}

int	bonus_rrr(t_list **a, t_list **b)
{
	if (*a == NULL || *b == NULL)
		return (0);
	rotate_down(a);
	rotate_down(b);
	return (1);
}
