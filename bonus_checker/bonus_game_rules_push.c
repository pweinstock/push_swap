/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game_rules_push.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:05:16 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/13 14:29:45 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

int	bonus_pa(t_list **a, t_list **b)
{
	if (*b == NULL)
		return (0);
	push(top(*b), a);
	pop(b);
	return (1);
}

int	bonus_pb(t_list **a, t_list **b)
{
	if (*a == NULL)
		return (0);
	push(top(*a), b);
	pop(a);
	return (1);
}
