/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiacore-da <ldiacore-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:30:25 by ldiacore-da          #+#    #+#             */
/*   Updated: 2025/06/02 15:28:01 by ldiacore-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **head)
{
	t_stack	*tmp;

	if (lst_size(head) <= 1)
		return (0);
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
	return (1);
}

int	sa(t_core *core)
{
	if (swap(core->a))
	{
		if (core->print)
			ft_printf("sa\n");
		upd_cost(core);
		return (1);
	}
	return (0);
}

int	sb(t_core *core)
{
	if (swap(core->b))
	{
		if (core->print)
			ft_printf("sb\n");
		upd_cost(core);
		return (1);
	}
	return (0);
}

int	ss(t_core *core)
{
	if (swap(core->a) && swap(core->b))
	{
		if (core->print)
			ft_printf("ss\n");
		upd_cost(core);
		return (1);
	}
	return (0);
}
