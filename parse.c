/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:17:02 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/07 18:57:05 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse(element **stack, int argc, char **argv)
{
	int	i;
	int	j;
	char	**nbrs;
	int	nbrs_len;
	
	i = argc - 1;
	while (i > 0)
	{
		nbrs = ft_split(argv[i], ' ');
		nbrs_len = ft_size_of_array(nbrs) - 1;
		while(nbrs_len >= 0)
		{
			j = 0;
			while(nbrs[nbrs_len][j] != 0)
			{
				if(!ft_isdigit(nbrs[nbrs_len][j]) && nbrs[nbrs_len][j] != '-')
					return (0);
				j++;
			}
			push(ft_atoi(nbrs[nbrs_len]), stack);
			nbrs_len--;
		}	
		i--;
	}
	return (1);
}

int	ft_double_check(element **stack)
{
	int	*array;
	int	i;
	int	j;
	int	stacksize;

	i = 0;
	stacksize = ft_stacksize(stack);
	array = (int *)malloc(sizeof(int) * (stacksize + 1));
	while(*stack)
	{
		array[i] = (*stack)->content;
		stack = &(*stack)->next;
		i++;
	}
	i = 0;
	while(i <= stacksize)
	{
		j = 0;
		while(j < i)
		{
			if(array[j] == array[i])
			{
				free(array);
				return (1);
			}	
			j++;	
		}
		i++;
	}
	free(array);
	return (0);
}

int	ft_size_of_array(char **array)
{
	int	i;

	i = 0;
	while(array[i])
		i++;
	return(i);
}

void	ft_free_stack(element **stack)
{
	int	stack_size;
	int	i;

	stack_size = ft_stacksize(stack);
	i = 0;
	while(i < stack_size)
	{
		pop(stack);
		i++;
	}
}