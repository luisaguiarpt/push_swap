/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:13:53 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/23 12:48:21 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_cost(t_stack *elem, t_core *core, char stack);

void	upd_cost(t_core *core)
{
	t_stack	*a;
	t_stack	*b;

	a = *core->a;
	b = *core->b;
	upd_moves(core);
	while (a)
	{
		a->cost = calc_cost(a, core, 'a');
		a = a->next;
	}
	while (b)
	{
		b->cost = calc_cost(b, core, 'b');
		b = b->next;
	}
}

static int	calc_cost(t_stack *elem, t_core *core, char stack)
{
	t_stack	*target;
	int		cost;

	if (stack == 'a')
		target = get_target_below(core->b, elem);
	else
		target = get_target_above(core->a, elem);
	if (!target)
		target = elem;
	cost = 0;
	if (elem->moves >= 0 && target->moves >= 0)
		cost = ft_max(elem->moves, target->moves);
	else if (elem->moves < 0 && target->moves < 0)
		cost = ft_max(ft_abs(elem->moves), ft_abs(target->moves));
	else if (elem->moves >= 0 && target->moves < 0)
		cost = elem->moves + ft_abs(target->moves);
	else if (elem->moves < 0 && target->moves >= 0)
		cost = ft_abs(elem->moves) + target->moves;
	return (cost);
}

t_stack	*get_max_index(t_stack **head)
{
	int		max;
	t_stack	*lst;

	lst = *head;
	max = 0;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	lst = *head;
	while (lst)
	{
		if (lst->index == max)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_stack *get_min_index(t_stack **head)
{
	int		min;
	t_stack	*lst;

	lst = *head;
	min = INT_MAX;
	while (lst)
	{
		if (lst->index < min)
			min = lst->index;
		lst = lst->next;
	}
	lst = *head;
	while (lst)
	{
		if (lst->index == min)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
