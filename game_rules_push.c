/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:05:16 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/06 15:06:08 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "pb\n", 3);
}
