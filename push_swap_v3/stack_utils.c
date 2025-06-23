/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:55:22 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/23 11:58:47 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	lst_size(t_stack **head)
{
	t_stack	*ptr;
	int		size;

	ptr = *head;
	size = 0;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}

t_stack	*lst_last(t_stack **head)
{
	t_stack	*last;

	last = *head;
	if (lst_size(head) == 0)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

t_stack	*lst_2ndlast(t_stack **head)
{
	t_stack	*last;
	t_stack	*second_last;

	last = lst_last(head);
	second_last = *head;
	while (second_last->next != last)
		second_last = second_last->next;
	return (second_last);
}

void	lst_copy(t_stack **orig, t_stack **dest)
{
	t_stack	*tmp;
	t_stack	*tmp_o;

	tmp_o = *orig;
	while (tmp_o)
	{
		tmp = lst_new(tmp_o->value);
		tmp->index = tmp_o->index;
		tmp->cost = tmp_o->cost;
		lstadd_back(dest, tmp);
		tmp_o = tmp_o->next;
	}
}
