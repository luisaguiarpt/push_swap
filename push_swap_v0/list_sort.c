/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:55:22 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 16:58:41 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_swap(t_list **begin, t_list **curr, t_list **prev, int *f)
{
	t_list	*tmp;

	tmp = (*curr)->next;
	(*curr)->next = tmp->next;
	tmp->next = (*curr);
	if (*prev)
		(*prev)->next = tmp;
	else
		*begin = tmp;
	*curr = tmp;
	*f = 1;
}

void	sort_list(t_list **begin, int (*cmp)())
{
	t_list	*curr;
	t_list	*prev;
	int		flag;

	flag = 1;
	if (!begin || !*begin)
		return ;
	while (flag)
	{
		flag = 0;
		prev = NULL;
		curr = *begin;
		while (curr && curr->next)
		{
			if (cmp(curr->value, curr->next->value))
				list_swap(begin, &curr, &prev, &flag);
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}
	}
}
