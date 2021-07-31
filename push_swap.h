/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:15:12 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/31 20:57:26 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>

typedef struct node
{
	int			content;
	struct node	*next;
}				element;

//stack_utils
void	push(int content, element **stack);
void	pop(element **stack);
int		top(element *stack);

//game_rules
void	swap(element **stack);
void	sa(element **stack);
void	sb(element **stack);
void	ss(element **stack_a, element **stack_b);
void	pa(element **stack_a, element **stack_b);
void	pb(element **stack_a, element **stack_b);
void	rotate_up(element **stack);
void	ra(element **stack);
void	rb(element **stack);
void	rr(element **stack_a, element **stack_b);
void	rotate_down(element **stack);
void	rra(element **stack);
void	rrb(element **stack);
void	rrr(element **stack_a, element **stack_b);

#endif