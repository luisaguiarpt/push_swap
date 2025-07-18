/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:48:13 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/23 18:04:31 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_core *core)
{
	t_stack	*high;
	t_stack	*low;
	t_stack	**head;

	head = core->a;
	high = get_max_index(core->a);
	low = get_min_index(core->a);
	if (*head == high)
		ra(core);
	else if ((*head)->next == high)
		rra(core);
	if (*head != low)
		sa(core);
}

void	sort_5(t_core *core)
{
	t_stack	**b;
	t_stack	*target;

	b = core->b;
	if (is_sorted(core))
		return ;
	while (lst_size(core->a) > 3)
		pb(core);
	sort_3(core);
	while (lst_size(core->b))
	{
		upd_moves(core);
		target = get_target_a(core->a, *b);
		while (target->moves > 0)
			ra(core);
		while (target->moves < 0)
		rra(core);
		pa(core);
	}
	rot_min_top_a(core);
}

t_stack	*get_target_a(t_stack **a, t_stack *ref)
{
	int		diff;
	t_stack	*p_a;
	t_stack	*prev;

	diff = INT_MAX;
	p_a = *a;
	prev = NULL;
	while (p_a)
	{
		if (p_a->index > ref->index && ft_abs(p_a->index - ref->index) < diff)
		{
			diff = ft_abs(p_a->index - ref->index);
			prev = p_a;
		}
		p_a = p_a->next;
	}
	if (diff == INT_MAX)
		prev = get_min_index(a);
	return (prev);
}

void	rot_min_top_a(t_core *core)
{
	t_stack	*min;

	min = get_min_index(core->a);
	if (min->moves < 0)
		while (*core->a != min)
			rra(core);
	else if (min->moves > 0)
		while (*core->a != min)
			ra(core);
}
