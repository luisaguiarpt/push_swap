/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:55:22 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 16:58:41 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	new->cost = 0;
	new->i = 0;
	return (new);
}

void	lst_delone(t_list **lst)
{
	if (!lst)
		return ;
	free(*lst);
	*lst = NULL;
}

int	lst_size(t_list **head)
{
	t_list	*ptr;
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

t_list	*lst_last(t_list **head)
{
	t_list	*last;

	last = *head;
	if (lst_size(head) == 0)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

t_list	*lst_2ndlast(t_list **head)
{
	t_list	*last;
	t_list	*second_last;

	last = lst_last(head);
	second_last = *head;
	while (second_last->next != last)
		second_last = second_last->next;
	return (second_last);
}
