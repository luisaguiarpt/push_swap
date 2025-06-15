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

int	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!from || !*from || !to)
		return (0);
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
	return (1);
}

int	pa(t_stacks *s)
{
	if (push(s->b, s->a))
	{
		if (s->print)
			ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	pb(t_stacks *s)
{
	if (push(s->a, s->b))
	{
		if (s->print)
			ft_printf("pb\n");
		return (1);
	}
	return (0);
}
