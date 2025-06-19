/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:35:02 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 16:52:25 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!head || !(*head) || lst_size(head) < 2)
		return (0);
	tmp = (*head)->next;
	last = lst_last(head);
	last->next = *head;
	(*head)->next = NULL;
	*head = tmp;
	return (1);
}

int	ra(t_core *core)
{
	if (rotate(core->a))
	{
		if (core->print)
			ft_printf("ra\n");
		upd_cost(core);
		core->tmp_cost += 1;
		return (1);
	}
	return (0);
}

int	rb(t_core *core)
{
	if (rotate(core->b))
	{
		if (core->print)
			ft_printf("rb\n");
		upd_cost(core);
		core->tmp_cost += 1;
		return (1);
	}
	return (0);
}

int	rr(t_core *core)
{
	if (rotate(core->a) && rotate(core->b))
	{
		if (core->print)
			ft_printf("rr\n");
		upd_cost(core);
		core->tmp_cost += 1;
		return (1);
	}
	return (0);
}
