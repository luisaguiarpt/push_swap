/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:25:01 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:48:13 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *array, int size);
static int	*value_array(t_stack **head, int size);
static void	assign_index_chunk(t_core *core, int *array, int size);

void	assign_attr(t_core *core)
{
	int	*array;
	int	size;

	size = lst_size(core->a);
	array = value_array(core->a, size);
	if (!array)
		free_error(core);
	sort_array(array, size);
	assign_index_chunk(core, array, size);
	free(array);
}

/**
 * @brief	Assigns an index and a chunk to each element of the list based 
 * on a sorted array containg the values of the elements of said list
 * @param	s		Structure that holds stacks A and B
 * @param	array	Array with the values of the list in a sorted order
 * @param	size	Size of the array
 */
static void	assign_index_chunk(t_core *core, int *array, int size)
{
	int		i;
	t_stack	**head;

	head = core->a;
	while (*head)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == (*head)->value)
			{
				(*head)->i = i;
				(*head)->chunk = i / ft_sqrt_approx(core->size);
				if ((*head)->chunk >= core->nbr_chunks)
					core->nbr_chunks = (*head)->chunk + 1;
			}
			i++;
		}
		head = &(*head)->next;
	}
}

t_stack	*get_max_index(t_stack **head)
{
	int		max;
	t_stack	*lst;

	lst = *head;
	max = 0;
	while (lst)
	{
		if (lst->i > max)
			max = lst->i;
		lst = lst->next;
	}
	lst = *head;
	while (lst)
	{
		if (lst->i == max)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
/**
 * @brief	Returns an int array composed of all the values in the list
 * @param	head	Pointer to the first element of the list (stack)
 * @param	size	Size of the list
 * @return	Int array with all the values that are to be sorted
 */
static int	*value_array(t_stack **head, int size)
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
