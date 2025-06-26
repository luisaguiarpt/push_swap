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

t_stack	*get_cheapest(t_stack **head)
{
	t_stack	*a;
	t_stack	*cheapest;
	int		min;

	a = *head;
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

t_stack	*get_target_below(t_stack **stack, t_stack *ref)
{
	int		diff;
	t_stack	*p_stack;
	t_stack	*prev;

	diff = INT_MAX;
	p_stack = *stack;
	prev = NULL;
	while (p_stack)
	{
		if (p_stack->index < ref->index && 
				ft_abs(p_stack->index - ref->index) < diff)
		{
			diff = ft_abs(p_stack->index - ref->index);
			prev = p_stack;
		}
		p_stack = p_stack->next;
	}
	if (diff == INT_MAX)
		prev = get_max_index(stack);
	return (prev);
}

t_stack	*get_target_above(t_stack **stack, t_stack *ref)
{
	int		diff;
	t_stack	*p_stack;
	t_stack	*prev;

	diff = INT_MAX;
	p_stack = *stack;
	prev = NULL;
	while (p_stack)
	{
		if (p_stack->index > ref->index && 
				ft_abs(p_stack->index - ref->index) < diff)
		{
			diff = ft_abs(p_stack->index - ref->index);
			prev = p_stack;
		}
		p_stack = p_stack->next;
	}
	if (diff == INT_MAX)
		prev = get_min_index(stack);
	return (prev);
}

int	is_sorted(t_core *core, char stack)
{
	t_core	*copy;
	t_stack	*prev;

	copy = copy_core(core);
	rot_min_top(copy, stack);
	if (stack == 'a')
		prev = *copy->a;
	else
		prev = *copy->b;
	while (prev->next)
	{
		if (prev->value < prev->next->value)
			prev = prev->next;
		else
		{
			free_all(copy);
			return (0);
		}
	}
	free_all(copy);
	return (1);
}
