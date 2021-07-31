/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:03:58 by pweinsto          #+#    #+#             */
/*   Updated: 2021/07/31 20:57:23 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include "push_swap.h"

void	ft_print_stack(element *stack)
{
	while(stack->next != NULL)
	{
		printf("content: %d\n", stack->content);
		stack = stack->next;
	}
	printf("content: %d\n", stack->content);
	printf("stack\n");
}

int	main(int argc, char **argv)
{
	element	*a;
	element	*b;
	int i;

	//printf("argc: %d\n", argc);
	a = (element *)malloc(sizeof(element));
	a->content = ft_atoi(argv[argc - 1]);
	a->next = NULL;
	b = (element *)malloc(sizeof(element));
	b->content = 20;
	b->next = NULL;
	push(15, &b);
	//printf("top: %d\n", top(a));
	i = argc - 2;
	while (i > 0)
	{
		push(ft_atoi(argv[i]), &a);
		//printf("top: %d\n", top(a));
		i--;
	}
	ft_print_stack(a);
	ft_print_stack(b);
	rrr(&a, &b);
	ft_print_stack(a);
	ft_print_stack(b);
	return (0);
}
