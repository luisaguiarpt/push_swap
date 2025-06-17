/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:55:22 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 16:58:41 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_cost(t_stack **lst);

void	upd_cost(t_core *core)
{
	calc_cost(core->a);
	calc_cost(core->b);
}

/**
 * @brief	Calculates the cost of moving an element from one stack to another
 * @param	lst	Stack in which to calculate the cost
 */
void	calc_cost(t_stack **head)
{
	t_stack	*lst;
	int		median;
	int		size;
	int		i;

	lst = *head;
	size = lst_size(head);
	median = size / 2;
	i = 0;
	while (lst)
	{
		if (i <= median)
			lst->cost = i;
		else
			lst->cost = - (size - i);
		i++;
		lst = lst->next;
	}
}

/**
 * @brief	Returns the cost of the element of the stack with index <index>
 * @param	lst		Pointer to head of stack
 * @param	index	Index of the element of the list to get cost from
 * @return	Cost of the element
 * @retval	(-1)	No match found
 */
int	get_cost(t_stack **head, int index)
{
	t_stack	*lst;

	lst = *head;
	while (lst)
	{
		if (lst->i == index)
			return (lst->cost);
		lst = lst->next;
	}
	return (-1);
}
