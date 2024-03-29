/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:03:58 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/11 16:40:14 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!ft_parse(&a, argc, argv))
	{
		write(2, "Error\n", 6);
		ft_free_stack(&a);
		free(a);
		return (0);
	}
	if (ft_double_check_1(&a))
	{
		write(2, "Error\n", 6);
		ft_free_stack(&a);
		free(a);
		return (0);
	}
	ft_sort(&a, &b);
	ft_free_stack(&a);
	free(a);
	return (0);
}
