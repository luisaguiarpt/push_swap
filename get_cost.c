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

void	get_cost(t_stacks *s)
{
	t_list	*head;
	int		median;
	int		size;
	int		i;

	head = *s->a;
	size = lst_size(s->a);
	median = size / 2;
	i = 0;
	while (head)
	{
		if (i <= median)
			head->cost = i + 1;
		else
			head->cost = size - i + 1;
		i++;
		head = head->next;
	}
}
