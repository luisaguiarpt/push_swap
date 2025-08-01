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
	new->chunk = 0;
	new->i = 0;
	new->curr_pos = 0;
	return (new);
}

void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*lst_find(t_list **head, int value, char attr)
{
	t_list	*lst;

	lst = *head;
	while (attr == 'i' && lst)
	{
		if (lst->i == value)
			return (lst);
		lst = lst->next;
	}
	while (attr == 'c' && lst)
	{
		if (lst->chunk == value)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
