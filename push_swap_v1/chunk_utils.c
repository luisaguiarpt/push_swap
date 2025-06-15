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

/**
 * @brief	For each element in stack A it initializes the chunk variable to 
 * represent the chunk the element belongs to (depends on the index)
 * @param	s	Structure that holds stacks A and B
 * @return	i	Index of the element we're assign to the chunk
 */
int	get_chunk(t_stacks *s, int i)
{
	int		chunk_size;
	
	if (s->size < 100)
		chunk_size = ft_sqrt_approx(s->size);
	else
		chunk_size = 25;
	return (i / chunk_size);
}

/**
 * @brief	Loops through stack A to find the highest chunk number
 * (i.e. number of chunks)
 * @param	s	Structure that holds stacks A and B
 * @return	Highest chunk number that was assigned
 */
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

/**
 * @brief	Creates an array of ints that relates the chunk number to the
 * number of elements in that chunk
 * @param	s	Structure that holds stacks A and B
 * @return	An array of ints that relates the chunk number to the number of
 * elements in that chunk
 */
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

/**
 * @brief	Finds the element with the lowest cost in a chunk
 * @param	lst		Stack in which to locate the lowest cost element
 * @param	chunk	Chunk number of element to locate
 * @return	Pointer to the lowest cost element
 */
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
