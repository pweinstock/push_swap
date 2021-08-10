/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:15:12 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/10 17:16:16 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h> // delete this !!!!

typedef struct node
{
	int			content;
	struct node	*next;
}				t_list;

typedef struct chunk
{
	int	index1;
	int	index2;
	int	index3;
	int	index4;
	int	index5;
	int	index6;
	int	index7;
}				t_chunks;

typedef struct chunk_para
{
	int	i;
	int	stack_a_size;
}				t_cp;

//printing delete this!!!
void	ft_print_stack(t_list *stack);

//parse
int		ft_parse(t_list **stack, int argc, char **argv);
int		ft_double_check(t_list **stack);
int		ft_size_of_array(char **array);
void	ft_free_stack(t_list **stack);

//game_rules_swap
void	swap(t_list **stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **a, t_list **b);

//game_rules_push
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

//game_rules_rotate_up
void	rotate_up(t_list **stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **a, t_list **b);

//game_rules_rotate_down
void	rotate_down(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **a, t_list **b);

//sort
void	_3(t_list **stack);
void	_0_10(t_list **a, t_list **b);
void	_11_100(t_list **a, t_list **b);
void	_101_500(t_list **a, t_list **b);

//sort_utils_1
int		ft_stacksize(t_list **stack);
int		ft_minindex(t_list **stack);
int		ft_maxindex(t_list **stack);
void	ft_index_to_top(t_list **stack, int index);
int		ft_get_index(t_list **a, int index);
void	ft_index_to_top_b(t_list **stack, int index);

//sort_utils_2
int		ft_sort_check(t_list **stack);
void	ft_push_4_chunks(t_list **a, t_list **b);
void	ft_push_chunks_back(t_list **a, t_list **b);
void	ft_push_8_chunks_1(t_list **a, t_list **b);
void	ft_push_8_chunks_2(t_list **a, t_list **b, t_chunks chunk, t_cp para);
void	ft_push_8_chunks_3(t_list **a, t_list **b, t_chunks chunk, t_cp para);

//stack_utils
void	push(int content, t_list **stack);
void	pop(t_list **stack);
int		top(t_list *stack);

//quicksort
void	quickSort(int *array, int low, int high);
void	ft_stack_array_4(t_list **stack, t_chunks *chunk);
void	ft_stack_array_8(t_list **stack, t_chunks *chunk);

#endif