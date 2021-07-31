/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:29:33 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/31 20:57:27 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int content, element **stack)
{
	element	*Element;

	Element = (element *)malloc(sizeof(element));
	Element->content = content;
	Element->next = *stack;
	*stack = Element;
}

void	pop(element **stack)
{
	element *ptr;

	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}

int	top(element *stack)
{
	return (stack->content);
}
