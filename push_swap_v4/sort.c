#include "push_swap.h"

void	sort(t_core *core)
{
	if (is_sorted(core, 'a'))
	{
		rot_min_top(core, 'a');
		free_all(core);
		exit(0);
	}
	while (lst_size(core->a) > 3)
	{
		upd_cost(core);
		move_cheapest_top_a(core);
		pb(core);
	}
	sort_3(core);
	while (lst_size(core->b))
	{
		upd_cost(core);
		move_cheapest_top_b(core);
		pa(core);
	}
	rot_min_top(core, 'a');
}

void	move_cheapest_top_a(t_core *core)
{
	t_stack	*cheapest;
	t_stack	*target;

	cheapest = get_cheapest(core->a);
	target = get_target_below(core->b, cheapest);
	while (target && cheapest->moves > 0 && target->moves > 0)
		rr(core);
	while (target && cheapest->moves < 0 && target->moves < 0)
		rrr(core);
	while (target && target->moves > 0)
		rb(core);
	while (target && target->moves < 0)
		rrb(core);
	while (cheapest->moves > 0)
		ra(core);
	while (cheapest->moves < 0)
		rra(core);
}

void	move_cheapest_top_b(t_core *core)
{
	t_stack	*cheapest;
	t_stack	*target;

	cheapest = get_cheapest(core->b);
	target = get_target_above(core->a, cheapest);
	while (target && cheapest->moves > 0 && target->moves > 0)
		rr(core);
	while (target && cheapest->moves < 0 && target->moves < 0)
		rrr(core);
	while (target && target->moves > 0)
		ra(core);
	while (target && target->moves < 0)
		rra(core);
	while (cheapest->moves > 0)
		rb(core);
	while (cheapest->moves < 0)
		rrb(core);
}

void	rot_max_top(t_core *core, char stack)
{
	t_stack	*max;
	t_stack	**head;

	if (stack == 'a')
		head = core->a;
	else
		head = core->b;
	max = get_max_index(head);
	upd_cost(core);
	if (max->moves < 0)
		while (*head != max)
			rrb(core);
	else if (max->moves > 0)
		while (*head != max)
			rb(core);
}

void	rot_min_top(t_core *core, char stack)
{
	t_stack	*min;
	t_stack	**head;

	if (stack == 'a')
		head = core->a;
	else
		head = core->b;
	min = get_min_index(head);
	upd_cost(core);
	if (min->moves < 0)
		while (*head != min)
			rra(core);
	else if (min->moves > 0)
		while (*head != min)
			ra(core);
}
