#include "push_swap.h"

void	sort(t_core *core)
{
	while (lst_size(core->a) > 5)
	{
		upd_moves(core);
		upd_cost(core);
		move_cheapest(core);
	}
}

void	move_cheapest(t_core *core)
{
	t_stack	*cheapest;
	t_stack	*target;

	cheapest = get_cheapest(core);
	target = get_target(core);
	while (target && cheapest->moves > 0 && target->moves > 0)
	{

	}
}
