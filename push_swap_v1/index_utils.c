/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:55:22 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 16:58:41 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_array(t_list **head, int size);
static void	sort_array(int *array, int size);
static void	assign_index_and_chunk(t_stacks *s, int *array, int size);

/**
 * @brief	Assigns an index and chunk to each element of the stacks based on 
 * their sortedness
 * @param	s	Structure that holds stacks A and B
 * @notes	This function must only be called once after stack A is initialized
 */
void	get_index_and_chunk(t_stacks *s)
{
	int	*array;
	int	size;

	size = lst_size(s->a);
	array = get_array(s->a, size);
	if (!array)
		free_error(s);
	sort_array(array, size);
	assign_index_and_chunk(s, array, size);
	free(array);
}

/**
 * @brief	Returns an int array composed of all the values in the list
 * @param	head	Pointer to the first element of the list (stack)
 * @param	size	Size of the list
 * @return	Int array with all the values that are to be sorted
 */
static int	*get_array(t_list **head, int size)
{
	int	*array;
	int	i;

	array = ft_calloc(size, sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (*head)
	{
		array[i] = (*head)->value;
		head = &(*head)->next;
		i++;
	}
	return (array);
}

/**
 * @brief	Sorts an integer array
 * @param	array	Array to be sorted
 * @param	size	Size of the array to be sorted
 */
static void	sort_array(int *array, int size)
{
	int	i;
	int	tmp;
	int	flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				flag = 1;
			}
			i++;
		}
	}
}

/**
 * @brief	Assigns an index and a chunk to each element of the list based 
 * on a sorted array containg the values of the elements of said list
 * @param	s		Structure that holds stacks A and B
 * @param	array	Array with the values of the list in a sorted order
 * @param	size	Size of the array
 */
static void	assign_index_and_chunk(t_stacks *s, int *array, int size)
{
	int		i;
	t_list	**head;

	head = s->a;
	while (*head)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == (*head)->value)
			{
				(*head)->i = i;
				(*head)->chunk = get_chunk(s, i);
			}
			i++;
		}
		head = &(*head)->next;
	}
}
