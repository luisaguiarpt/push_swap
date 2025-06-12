/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:55:22 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 16:58:41 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk(t_stacks *s, int i)
{
	int		chunk_size;
	
	if (s->size < 100)
		chunk_size = ft_sqrt_approx(s->size);
	else
		chunk_size = 25;
	return (i / chunk_size);
}

int	get_nbr_chunks(t_stacks *s)
{
	int		max;
	t_list	*tmp;

	tmp = *s->a;
	max = 0;
	while (tmp)
	{
		if (tmp->chunk > max)
			max = tmp->chunk;
		tmp = tmp->next;
	}
	return (max + 1);
}

int	*get_chunk_sizes(t_stacks *s)
{
	t_list	*head;
	int		*array;

	array = ft_calloc(s->nbr_chunks, sizeof(int));
	if (!array)
		free_error(s);
	head = *s->a;
	while (head)
	{
		array[head->chunk] += 1;
		head = head->next;
	}
	return (array);
}

t_list	*get_cheapest_in_chunk(t_list **lst, int chunk)
{
	int		min;
	t_list	*cheapest;
	t_list	*tmp;

	tmp = *lst;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->chunk == chunk && tmp->cost < min)
		{
			cheapest = tmp;
			min = tmp->cost;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}
