/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:05:16 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/10 17:11:10 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	push(top(*b), a);
	pop(b);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(top(*a), b);
	pop(a);
	write(1, "pb\n", 3);
}
