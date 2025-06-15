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
	int	cheapest;

	i = 0;
	while (i != s->nbr_chunks)
	{
		cheapest = get_cheapest_chunk(s);
		prt_lst(s->a);
		ft_printf("Cheapest chunk: %d\n", cheapest);
		push_chunk_b(s, cheapest);
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
	int			i;

	i = 0;
	while (i < s->nbr_chunks)
	{
		min = INT_MAX;
		copy = copy_stack(s);
		tmp = push_chunk_b(copy, i);
		if (tmp < min)
			min = tmp;
		free_all(copy);
		i++;
	}
	return (tmp);
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
		get_cost(s);
		sum_cost += push_cheapest_b(s, chunk);
		i++;
	}
	return (sum_cost);
}

/**
 * @brief	Push the cheapest element of a chunk to stack b
 * @param	s		Stack in which the operations are being performed
 * @param	chunk	Chunk out of which to push the cheapest element
 * @return	Cost of pushing the cheapest element
 */
int	push_cheapest_b(t_stacks *s, int chunk)
{
	t_list	*cheapest;

	upd_pos(s->a);
	cheapest = get_cheapest_in_chunk(s->a, chunk);
	while (cheapest->curr_pos != 0)
	{
		if (cheapest->curr_pos <= lst_size(s->a) / 2)
			ra(s);
		else
			rra(s);
		prt_stacks(s);
		upd_pos(s->a);
	}
	pb(s);
	prt_stacks(s);
	return (cheapest->cost);
}
