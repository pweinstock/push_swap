/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game_rules_rotate_up.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:06:52 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/13 14:34:43 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

void	bonus_rotate_up(t_list **stack)
{
	t_list	*ptr;

	ptr = *stack;
	*stack = (*stack)->next;
	while ((*stack)->next != NULL)
		stack = &(*stack)->next;
	(*stack)->next = ptr;
	(*stack)->next->next = NULL;
}

int	bonus_ra(t_list **stack)
{
	if (*stack == NULL)
		return (0);
	rotate_up(stack);
	return (1);
}

int	bonus_rb(t_list **stack)
{
	if (*stack == NULL)
		return (0);
	rotate_up(stack);
	return (1);
}

int	bonus_rr(t_list **a, t_list **b)
{
	if (*a == NULL || *b == NULL)
		return (0);
	rotate_up(a);
	rotate_up(b);
	return (1);
}
