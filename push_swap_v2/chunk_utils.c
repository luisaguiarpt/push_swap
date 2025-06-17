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
 * @brief	Creates an array of ints that relates the chunk number to the
 * number of elements in that chunk
 * @param	s	Structure that holds stacks A and B
 * @return	An array of ints that relates the chunk number to the number of
 * elements in that chunk
 */
int	*chunk_size_array(t_core *core)
{
	int		*array;
	t_stack	*head;

	array = ft_calloc(core->nbr_chunks, sizeof(int));
	if (!array)
		free_error(core);
	head = *core->a;
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
t_stack	*cheapest_in_chunk(t_stack **lst, int chunk)
{
	int		min;
	t_stack	*cheapest;
	t_stack	*tmp;

	tmp = *lst;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->chunk == chunk && ft_abs(tmp->cost) < min)
		{
			cheapest = tmp;
			min = tmp->cost;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

int	ischunk_in_stack(t_stack **head, int chunk)
{
	t_stack	*lst;

	lst = *head;
	while (lst)
	{
		if (lst->chunk == chunk)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	chunks_in_stack(t_core *core)
{
	int		i;
	int		count;
	int		*array;
	t_stack	*lst;

	array = ft_calloc(core->nbr_chunks, sizeof(int));
	if (!array)
		free_error(core);
	lst = *core->a;
	while (lst)
	{
		if (array[lst->chunk] == 0)
			array[lst->chunk] = 1;
		lst = lst->next;
	}
	count = 0;
	i = 0;
	while (i < core->nbr_chunks)
		count += array[i++];
	free(array);
	return (count);
}
