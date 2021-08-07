/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:15:12 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/07 18:43:20 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h> // delete this !!!!

typedef struct node
{
	int			content;
	struct node	*next;
}				element;

typedef struct chunk
{
	int	index1;
	int	index2;
	int	index3;
	int	index4;
	int	index5;
	int	index6;
	int	index7;
}				chunks;

typedef struct chunk_para
{
	int	i;
	int	stack_a_size;
}				chunks_para;


//printing delete this!!!
void	ft_print_stack(element *stack);

//parse
int	ft_parse(element **stack, int argc, char **argv);
int	ft_double_check(element **stack);
int	ft_size_of_array(char **array);
void	ft_free_stack(element **stack);

//game_rules_swap
void	swap(element **stack);
void	sa(element **stack);
void	sb(element **stack);
void	ss(element **stack_a, element **stack_b);

//game_rules_push
void	pa(element **stack_a, element **stack_b);
void	pb(element **stack_a, element **stack_b);

//game_rules_rotate_up
void	rotate_up(element **stack);
void	ra(element **stack);
void	rb(element **stack);
void	rr(element **stack_a, element **stack_b);

//game_rules_rotate_down
void	rotate_down(element **stack);
void	rra(element **stack);
void	rrb(element **stack);
void	rrr(element **stack_a, element **stack_b);

//sort
void	_3(element **stack);
void	_0_10(element **stack_a, element **stack_b);
void	_11_100(element **stack_a, element **stack_b);
void	_101_500(element **stack_a, element **stack_b);

//sort_utils_1
int		ft_stacksize(element **stack);
int		ft_minindex(element **stack);
int		ft_maxindex(element **stack);
void	ft_index_to_top(element **stack, int index);
int		ft_get_index(element **stack_a, int index);
void	ft_index_to_top_b(element **stack, int index);

//sort_utils_2
int		ft_sort_check(element **stack);
void	ft_push_4_chunks(element **stack_a, element **stack_b);
void	ft_push_chunks_back(element **stack_a, element **stack_b);
void	ft_push_8_chunks_1(element **stack_a, element **stack_b);
void	ft_push_8_chunks_2(element **stack_a, element **stack_b, chunks chunk, chunks_para para);
void	ft_push_8_chunks_3(element **stack_a, element **stack_b, chunks chunk, chunks_para para);

//stack_utils
void	push(int content, element **stack);
void	pop(element **stack);
int		top(element *stack);

//quicksort
void	quickSort(int *array, int low, int high);
void	ft_stack_array_4(element **stack, chunks *chunk);
void	ft_stack_array_8(element **stack, chunks *chunk);

#endif