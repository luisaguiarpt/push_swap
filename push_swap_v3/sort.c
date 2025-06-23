#include "push_swap.h"

void	sort(t_core *core)
{
	while (lst_size(core->a))
	{
		upd_moves(core);
		upd_cost(core);
		move_cheapest(core);
		pb(core);
		prt_core(core);
	}
}

void	move_cheapest(t_core *core)
{
	t_stack	*cheapest;
	t_stack	*target;

	cheapest = get_cheapest(core);
	target = get_target(core->b, cheapest);
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
