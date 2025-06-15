/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:30:25 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 15:28:01 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **head)
{
	t_list	*tmp;

	if (lst_size(head) <= 1)
		return (0);
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
	return (1);
}

int	sa(t_stacks *s)
{
	if (swap(s->a))
	{
		if (s->print)
			ft_printf("sa\n");
		upd_lst_cost(s);
		return (1);
	}
	return (0);
}

int	sb(t_stacks *s)
{
	if (swap(s->b))
	{
		if (s->print)
			ft_printf("sb\n");
		upd_lst_cost(s);
		return (1);
	}
	return (0);
}

int	ss(t_stacks *s)
{
	if (swap(s->a) && swap(s->b))
	{
		if (s->print)
			ft_printf("ss\n");
		upd_lst_cost(s);
		return (1);
	}
	return (0);
}
