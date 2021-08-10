/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:29:33 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/10 17:14:54 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int content, t_list **stack)
{
	t_list	*Element;

	Element = (t_list *)malloc(sizeof(t_list));
	Element->content = content;
	Element->next = *stack;
	*stack = Element;
}

void	pop(t_list **stack)
{
	t_list	*ptr;

	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}

int	top(t_list *stack)
{
	return (stack->content);
}
