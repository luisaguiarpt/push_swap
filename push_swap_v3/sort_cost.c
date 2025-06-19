#include "push_swap.h"

static int	calc_cost(t_stack *elem, t_core *core);
static t_stack	*get_target(t_stack **b, t_stack *ref);
static t_stack	*get_max_index(t_stack **head);

void	upd_cost(t_core *core)
{
	t_stack	*a;

	a = *core->a;
	while (a)
	{
		a->cost = calc_cost(a, core);
		a = a->next;
	}
}

static int	calc_cost(t_stack *elem, t_core *core)
{
	t_stack	*target;
	int		cost;

	target = get_target(core->b, elem);
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

static t_stack	*get_max_index(t_stack **head)
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
