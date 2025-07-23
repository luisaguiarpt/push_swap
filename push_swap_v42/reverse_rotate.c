/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:35:02 by ldias-da          #+#    #+#             */
/*   Updated: 2025/07/23 19:02:35 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate(t_stack **head)
{
	t_stack	*second_last;
	t_stack	*tmp;

	if (!head || !(*head) || lst_size(head) < 2)
		return (0);
	second_last = lst_2ndlast(head);
	tmp = second_last->next;
	tmp->next = *head;
	*head = tmp;
	second_last->next = NULL;
	return (1);
}

int	rra(t_core *core)
{
	if (rev_rotate(core->a))
	{
		if (core->print)
			ft_printf("rra\n");
		upd_cost(core);
		return (1);
	}
	return (0);
}

int	rrb(t_core *core)
{
	if (rev_rotate(core->b))
	{
		if (core->print)
			ft_printf("rrb\n");
		upd_cost(core);
		return (1);
	}
	return (0);
}

int	rrr(t_core *core)
{
	if (rev_rotate(core->a) && rev_rotate(core->b))
	{
		if (core->print)
			ft_printf("rrr\n");
		upd_cost(core);
		return (1);
	}
	return (0);
}
