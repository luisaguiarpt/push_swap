/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:39:10 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:43:07 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter(t_stacks *s)
{
	int	i;
	int	cheap_chunk;

	i = 0;
	while (i != s->nbr_chunks)
	{
		upd_lst_cost(s);
		cheap_chunk = get_cheapest_chunk(s);
		prt_lst(s->a);
		ft_printf("Cheapest chunk: %d\n", cheap_chunk);
		push_chunk_b(s, cheap_chunk);
		prt_stacks(s);
		i++;
	}
}

/**
 * @brief	Creates a copy of the original stack and pushes all the chunks,
 * one at a time, to find out which is the cheapest chunk to push
 * @param	s	Stack to copy
 * @return	Number of the cheapest chunk
 */
int	get_cheapest_chunk(t_stacks *s)
{
	t_stacks	*copy;
	int			min;
	int			tmp;
	int			cheapest;
	int			i;

	i = 0;
	min = INT_MAX;
	while (i < s->nbr_chunks)
	{
		copy = copy_stack(s);
		tmp = push_chunk_b(copy, i);
		if (tmp < min)
		{
			min = tmp;
			cheapest = i;
		}
		free_all(copy);
		i++;
	}
	return (cheapest);
}

/**
 * @brief	Push a chunk into stack b
 * @param	s		Stack in which the operations are being performed
 * @param	chunk	Chunk out of which to push all the elements
 * @return	Amount of operations needed to push all the elements of a chunk
 * @see		get_chunk_sizes(); get_cost();
 */
int	push_chunk_b(t_stacks *s, int chunk)
{
	int		sum_cost;
	int		i;

	sum_cost = 0;
	i = 0;
	s->chunk_sizes = get_chunk_sizes(s);
	while (i < s->chunk_sizes[chunk])
	{
		upd_lst_cost(s);
		sum_cost += push_cheapest_b(s, chunk);
		i++;
	}
	return (sum_cost);
}

/**
 * @brief	Moves the cheapest element in chunk and the target element from
 * stack B into position
 * @param	s		Stack in which the operations are being performed
 * @param	chunk	Chunk out of which to push all the elements
 * @return	Total cost of operations to move elements into position
 */
int	move_to_position(t_stacks *s, int chunk)
{
	t_list	*target;
	t_list	*cheap;
	int		tot_cost;

	upd_pos(s);
	cheap = get_cheapest_in_chunk(s->a, chunk);
	tot_cost = ft_abs(cheap->cost);
	target = lst_find(s->a, cheap->i - 1);
	if (target)
	{
		tot_cost += ft_abs(target->cost);
		while (cheap->cost > 1 && target->cost > 1)
			rr(s);
		while (cheap->cost < 1 && target->cost < 1)
			rrr(s);
		while (target->cost > 1)
			rb(s);
		while (target->cost < 1)
			rrb(s);
	}
	while (cheap->cost > 1)
		ra(s);
	while (cheap->cost < 1)
		rra(s);
	return (tot_cost);
}

/**
 * @brief	Push the cheapest element of a chunk to stack b
 * @param	s		Stack in which the operations are being performed
 * @param	chunk	Chunk out of which to push the cheapest element
 * @return	Cost of pushing the cheapest element
 */
int	push_cheapest_b(t_stacks *s, int chunk)
{
	t_list	*cheap;

	upd_pos(s);
	cheap = get_cheapest_in_chunk(s->a, chunk);
	while (cheap->curr_pos != 0)
	{
		upd_pos(s);
		if (cheap->curr_pos <= lst_size(s->a) / 2)
			ra(s);
		else
			rra(s);
		prt_stacks(s);
	}
	pb(s);
	prt_stacks(s);
	return (cheap->cost);
}
