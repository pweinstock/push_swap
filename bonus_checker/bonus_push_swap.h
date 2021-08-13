/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push_swap.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:51:37 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/13 14:07:55 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PUSH_SWAP_H
# define BONUS_PUSH_SWAP_H

# include "../push_swap.h"
# include "../bonus_get_next_line/bonus_get_next_line.h"

//bonus_checker
int		ft_apply_rules(t_list **a, t_list **b, char *rule);
int		ft_get_rules(t_list **a, t_list **b);
int		ft_bonus_order(t_list **a, t_list **b);
int		ft_no_error(t_list **a, int argc, char **argv);

//bonus_game_rules_swap
void	bonus_swap(t_list **stack);
int		bonus_sa(t_list **stack);
int		bonus_sb(t_list **stack);
int		bonus_ss(t_list **a, t_list **b);

//game_rules_push
int		bonus_pa(t_list **a, t_list **b);
int		bonus_pb(t_list **a, t_list **b);

//game_rules_rotate_up
void	bonus_rotate_up(t_list **stack);
int		bonus_ra(t_list **stack);
int		bonus_rb(t_list **stack);
int		bonus_rr(t_list **a, t_list **b);

//game_rules_rotate_down
void	bonus_rotate_down(t_list **stack);
int		bonus_rra(t_list **stack);
int		bonus_rrb(t_list **stack);
int		bonus_rrr(t_list **a, t_list **b);

#endif