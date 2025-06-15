/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:35:02 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:03:43 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate(t_list **head)
{
	t_list	*second_last;
	t_list	*tmp;

	if (!head || !(*head) || lst_size(head) < 2)
		return (0);
	second_last = lst_2ndlast(head);
	tmp = second_last->next;
	tmp->next = *head;
	*head = tmp;
	second_last->next = NULL;
	return (1);
}

int	rra(t_stacks *s)
{
	if (rev_rotate(s->a))
	{
		if (s->print)
			ft_printf("rra\n");	
		upd_lst_cost(s);
		return (1);
	}
	return (0);
}

int	rrb(t_stacks *s)
{
	if (rev_rotate(s->b))
	{
		if (s->print)
			ft_printf("rrb\n");	
		upd_lst_cost(s);
		return (1);
	}
	return (0);
}

int	rrr(t_stacks *s)
{
	if (rev_rotate(s->a) && rev_rotate(s->b))
	{
		if (s->print)
			ft_printf("rrr\n");	
		upd_lst_cost(s);
		return (1);
	}
	return (0);
}
