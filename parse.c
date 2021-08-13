/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:17:02 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/11 16:43:37 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse(t_list **stack, int argc, char **argv)
{
	int		i;
	char	**ptr;
	int		len;

	i = argc - 1;
	while (i > 0)
	{
		ptr = ft_split(argv[i], ' ');
		len = ft_size_of_array(ptr) - 1;
		while (len >= 0)
		{
			if (ft_error_check(ptr, len))
				return (0);
			push(ft_atoi(ptr[len]), stack);
			len--;
		}	
		i--;
		ft_free_split(ptr);
	}
	return (1);
}

int	ft_double_check_1(t_list **stack)
{
	int	*array;
	int	i;
	int	stacksize;

	i = 0;
	stacksize = ft_stacksize(stack);
	array = (int *)malloc(sizeof(int) * (stacksize + 1));
	while (*stack)
	{
		array[i] = (*stack)->content;
		stack = &(*stack)->next;
		i++;
	}
	return (ft_double_check_2(array, stacksize));
}

int	ft_double_check_2(int *array, int stacksize)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stacksize)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] == array[i])
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
	while (array[i])
		i++;
	return (i);
}

int	ft_error_check(char **ptr, int len)
{
	int	j;

	j = 0;
	while (ptr[len][j] != 0)
	{
		if (!ft_isdigit(ptr[len][j]) && ptr[len][j] != '-')
		{
			ft_free_split(ptr);
			return (1);
		}
		if (ptr[len][j] == '-' && !ft_isdigit(ptr[len][j + 1]))
		{
			ft_free_split(ptr);
			return (1);
		}
		j++;
	}
	if (ft_atoi(ptr[len]) > 2147483647 || ft_atoi(ptr[len]) < -2147483648)
	{
		ft_free_split(ptr);
		return (1);
	}
	return (0);
}
