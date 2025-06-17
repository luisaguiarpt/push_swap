/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:39:10 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:43:07 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_core *core)
{
	int	left;
	int	cheapest;

	left = chunks_in_stack(core);
	while (left)
	{
		cheapest = cheapest_chunk(core);
		push_chunk_b(core, cheapest);
//		prt_core(core);
		left = chunks_in_stack(core);
	}
	rot_max_to_top(core);
	push_all_a(core);
//	prt_core(core);
}

void	rot_max_to_top(t_core *core)
{
	t_stack	*max;

	max = get_max_index(core->b);
	while (max->cost > 0)
		rb(core);
	while (max->cost < 0)
		rrb(core);
}

void	push_all_a(t_core *core)
{
	while (lst_size(core->b))
		pa(core);
}

int	push_chunk_b(t_core *core, int chunk)
{
	int		cost;

	cost = 0;
	upd_cost(core);
	if (!lst_find(core->a, chunk, 'c'))
		return (INT_MAX);
	while (lst_find(core->a, chunk, 'c'))
	{
		cost += ft_abs(move_to_position(core, chunk));
		cost += ft_abs(pb(core));
	}
	return (cost);
}

int	move_to_position(t_core *core, int chunk)
{
	t_stack	*cheap;
	t_stack	*target;

	core->tmp_cost = 0;
	cheap = cheapest_in_chunk(core->a, chunk);
	target = get_target(core->b, cheap);
	if (target)
	{
		while (cheap->cost > 0 && target->cost > 0)
			rr(core);
		while (cheap->cost < 0 && target->cost < 0)
			rrr(core);
		while (target->cost > 0)
			rb(core);
		while (target->cost < 0)
			rrb(core);
	}
	while (cheap->cost > 0)
		ra(core);
	while (cheap->cost < 0)
		rra(core);
	return (core->tmp_cost);
}
