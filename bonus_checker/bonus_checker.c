/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:03:46 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/13 14:06:22 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

int	ft_apply_rules(t_list **a, t_list **b, char *rule)
{
	if (ft_strncmp(rule, "sa\n", 3) == 0)
		return (bonus_sa(a));
	else if (ft_strncmp(rule, "sb\n", 3) == 0)
		return (bonus_sb(b));
	else if (ft_strncmp(rule, "ss\n", 3) == 0)
		return (bonus_ss(a, b));
	else if (ft_strncmp(rule, "pa\n", 3) == 0)
		return (bonus_pa(a, b));
	else if (ft_strncmp(rule, "pb\n", 3) == 0)
		return (bonus_pb(a, b));
	else if (ft_strncmp(rule, "ra\n", 3) == 0)
		return (bonus_ra(a));
	else if (ft_strncmp(rule, "rb\n", 3) == 0)
		return (bonus_rb(b));
	else if (ft_strncmp(rule, "rr\n", 3) == 0)
		return (bonus_rr(a, b));
	else if (ft_strncmp(rule, "rra\n", 3) == 0)
		return (bonus_rra(a));
	else if (ft_strncmp(rule, "rrb\n", 3) == 0)
		return (bonus_rrb(b));
	else if (ft_strncmp(rule, "rrr\n", 3) == 0)
		return (bonus_rrr(a, b));
	else
		return (0);
}

int	ft_get_rules(t_list **a, t_list **b)
{
	char	*rule;

	while (1)
	{
		rule = get_next_line(0);
		if (rule == NULL)
			return (1);
		if (!ft_apply_rules(a, b, rule))
			return (0);
	}
}

int	ft_bonus_order(t_list **a, t_list **b)
{
	if (*b != NULL)
		return (0);
	while ((*a)->next != NULL)
	{
		if ((*a)->content >= (*a)->next->content)
			return (0);
		*a = (*a)->next;
	}
	return (1);
}

int	ft_no_error(t_list **a, int argc, char **argv)
{
	if (!ft_parse(a, argc, argv))
	{
		write(2, "Error\n", 6);
		ft_free_stack(a);
		return (0);
	}
	if (ft_double_check_1(a))
	{
		write(2, "Error\n", 6);
		ft_free_stack(a);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!ft_no_error(&a, argc, argv))
	{
		free(a);
		return (0);
	}
	if (!ft_get_rules(&a, &b))
	{
		write(1, "KO\n", 3);
		ft_free_stack(&a);
		free(a);
		return (0);
	}
	if (ft_bonus_order(&a, &b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&a);
	free(a);
	return (0);
}
