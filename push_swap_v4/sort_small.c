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

	if (is_sorted(core, 'a'))
	{
		rot_min_top(core, 'a');
		return ;
	}
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
	if (is_sorted(core, 'a'))
	{
		rot_min_top(core, 'a');
		return ;
	}
	while (lst_size(core->a) > 3)
		pb(core);
	sort_3(core);
	upd_cost(core);
	while (lst_size(b))
	{
		target = get_target_above(core->a, *b);
		while (target->moves > 0)
			ra(core);
		while (target->moves < 0)
			rra(core);
		pa(core);
	}
	rot_min_top(core, 'a');
}
