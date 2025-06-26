/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:00:58 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 15:31:32 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!from || !*from || !to)
		return (0);
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
	return (1);
}

int	pa(t_core *core)
{
	if (push(core->b, core->a))
	{
		if (core->print)
			ft_printf("pa\n");
		upd_cost(core);
		return (1);
	}
	return (0);
}

int	pb(t_core *core)
{
	if (push(core->a, core->b))
	{
		if (core->print)
			ft_printf("pb\n");
		upd_cost(core);
		return (1);
	}
	return (0);
}
