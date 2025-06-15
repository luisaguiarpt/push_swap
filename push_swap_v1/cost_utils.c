/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:55:22 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 16:58:41 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost_all(t_list **lst);

void	upd_lst_cost(t_stacks *s)
{
	get_cost_all(s->a);
	get_cost_all(s->b);
}

/**
 * @brief	Calculates the cost of moving an element from one stack to another
 * @param	lst	Stack in which to calculate the cost
 */
void	get_cost_all(t_list **lst)
{
	t_list	*head;
	int		median;
	int		size;
	int		i;

	head = *lst;
	size = lst_size(lst);
	median = size / 2;
	i = 0;
	while (head)
	{
		if (i <= median)
			head->cost = i + 1;
		else
			head->cost = - (size - i + 1);
		i++;
		head = head->next;
	}
}

/**
 * @brief	Returns the cost of the element of the stack with index <index>
 * @param	lst		Pointer to head of stack
 * @param	index	Index of the element of the list to get cost from
 * @return	Cost of the element
 * @retval	(-1)	No match found
 */
int	get_cost(t_list **head, int index)
{
	t_list	*lst;

	lst = *head;
	while (lst)
	{
		if (lst->i == index)
			return (lst->cost);
		lst = lst->next;
	}
	return (-1);
}
