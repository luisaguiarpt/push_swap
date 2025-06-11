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
		upd_pos(s->a);
	}
	pb(s);
	return (cheapest->cost);
}

//void	sorter(t_stacks *s)
//{
//	int	i;
//
//	i = 0;
//	while (
//}
