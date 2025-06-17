/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:39:10 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:43:07 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_chunk(t_core *core)
{
	t_core	*copy;
	int		min;
	int		tmp;
	int		cheap;
	int		i;

	i = 0;
	min = INT_MAX;
	while (i < core->nbr_chunks)
	{
		if (!ischunk_in_stack(core->a, i))
		{
			i++;
			continue ;
		}
		copy = copy_core(core);
		tmp = push_chunk_b(copy, i);
		if (tmp < min)
		{
			min = tmp;
			cheap = i;
		}
		free_all(copy);
		i++;
	}
	return (cheap);
}

//t_stack	*get_target(t_core *core, t_stack *cheap)
//{
//	
//}

/**
 * @brief	Returns a pointer to an element in stack B that is the element with
 * the closest index that is also smaller than the argument
 * @param	b		Pointer to the head of stack b
 * @param	ref		Pointer to the reference member
 * @return	Pointer to target element
 * @notes	If there is no smaller element, it returns the biggest one
 */
t_stack	*get_target(t_stack **b, t_stack *ref)
{
	int		diff;
	t_stack	*ptr_b;
	t_stack	*prev;

	diff = INT_MAX;
	ptr_b = *b;
	prev = NULL;
	while (ptr_b)
	{
		if (ptr_b->i < ref->i && ft_abs(ptr_b->i - ref->i) < diff)
		{
			diff = ft_abs(ptr_b->i - ref->i);
			prev = ptr_b;
		}
		ptr_b = ptr_b->next;
	}
	if (diff == INT_MAX)
		prev = get_max_index(b);
	return (prev);
}
