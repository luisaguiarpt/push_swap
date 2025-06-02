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

int	rotate(t_list **head)
{
	t_list	*last;
	t_list	*tmp;

	if (!head || !(*head) || lst_size(head) < 2)
		return (0);
	tmp = (*head)->next;
	last = lst_last(head);
	last->next = *head;
	(*head)->next = NULL;
	*head = tmp;
	return (1);
}

int	ra(t_stacks *s)
{
	if (rotate(s->a))
		return (1);
	return (0);
}

int	rb(t_stacks *s)
{
	if (rotate(s->b))
		return (1);
	return (0);
}

int	rr(t_stacks *s)
{
	if (rotate(s->a) && rotate(s->b))
		return (1);
	return (0);
}
