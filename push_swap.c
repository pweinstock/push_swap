/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:03:58 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/10 17:27:18 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_list *stack)
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
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if(argc == 1)
		return (0);
	if(!ft_parse(&a, argc, argv))
	{
		write(2, "Error\n", 6);
		//ft_free_stack(&a);
		return (0);
	}
	if(ft_double_check(&a))
	{
		write(2, "Error\n", 6);
		//ft_free_stack(&a);
		return (0);
	}
	if(ft_stacksize(&a) + 1 <= 10)
		_0_10(&a, &b);
	else if(ft_stacksize(&a) + 1 <= 101)
		_11_100(&a, &b);
	else
		_101_500(&a, &b);
	//ft_free_stack(&a);
	//free(a);
	//system("leaks push_swap");
	return (0);
}