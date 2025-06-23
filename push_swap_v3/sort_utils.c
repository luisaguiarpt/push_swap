/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:47:37 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/23 17:47:40 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_core *core)
{
	t_stack	*a;
	t_stack	*cheapest;
	int		min;

	a = *core->a;
	cheapest = NULL;
	min = INT_MAX;
	while (a)
	{
		if (a->cost < min)
		{
			min = a->cost;
			cheapest = a;
		}
		a = a->next;
	}
	return (cheapest);
}

t_stack	*get_target(t_stack **b, t_stack *ref)
{
	int		diff;
	t_stack	*p_b;
	t_stack	*prev;

	diff = INT_MAX;
	p_b = *b;
	prev = NULL;
	while (p_b)
	{
		if (p_b->index < ref->index && ft_abs(p_b->index - ref->index) < diff)
		{
			diff = ft_abs(p_b->index - ref->index);
			prev = p_b;
		}
		p_b = p_b->next;
	}
	if (diff == INT_MAX)
		prev = get_max_index(b);
	return (prev);
}

int	is_sorted(t_stack **head)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr && ptr->next)
	{
		if (ptr->value < ptr->next->value)
			ptr = ptr->next;
		else if (ptr->value == get_max_index(head)->value 
				&& ptr->next->value == get_min_index(head)->value)
			ptr = ptr->next;
		else
			return (0);
	}
	return (1);
}

int	is_rev_sorted(t_stack **head)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr && ptr->next)
	{
		if (ptr->value > ptr->next->value)
			ptr = ptr->next;
		else if (ptr->value == get_min_index(head)->value && 
				ptr->next->value ==	get_max_index(head)->value)
			ptr = ptr->next;
		else
			return (0);
	}
	return (1);
}
